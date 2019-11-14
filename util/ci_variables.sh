#!/bin/bash

# Output environment variables
# Currently configured for Travis CI, obviously
echo -e "TRAVIS_REPO_SLUG = $TRAVIS_REPO_SLUG"
echo -e "TRAVIS_BRANCH = $TRAVIS_BRANCH"
echo -e "TRAVIS_COMMIT_RANGE = $TRAVIS_COMMIT_RANGE"
CURRENT_COMMIT_HASH=$(git rev-parse --short HEAD)
echo -e "CURRENT_COMMIT_HASH = $(git rev-parse --short HEAD)"
echo -e "CURRENT BRANCH = $(git rev-parse --abbrev-ref HEAD)"
echo -e "------------------------------------------------------------"

if [ "$TRAVIS_PULL_REQUEST" != "false" ]
then
    #############################
    # Triggered by pull request #
    #############################

    # Add QMK repository as `qmk`
    echo -e "Adding the official QMK repository as remote \e[33mqmk\e[0m..."
    git remote add qmk https://github.com/qmk/qmk_firmware.git

    # Fetch qmk:master
    echo -e "Fetching refs for \e[33mqmk:master\e[0m..."
    git fetch qmk master

    # Fetch the branch being targeted by the pull request, if it's not the master branch
    if [ $TRAVIS_BRANCH != "master" ]
    then
        echo -e "Fetching refs for \e[33mqmk:$TRAVIS_BRANCH\e[0m..."
        git fetch qmk $TRAVIS_BRANCH
    fi

    echo # echo a blank line because white space is nice

    # The SHA of qmk:master
    CURRENT_MASTER=$(git log -n 1 --pretty=format:"%H" qmk/master)
    echo -e "The current SHA of \e[33mqmk:master\e[0m is \e[32m$CURRENT_MASTER\e[0m"

    # The latest common ancestor of qmk:master and our development branch
    BRANCH_BASE=$(git merge-base ${CURRENT_MASTER} ${TRAVIS_BRANCH})
    echo -e "The latest common ancestor of \e[33mqmk:master\e[0m and \e[33mthis branch\e[0m is \e[32m$BRANCH_BASE\e[0m"
    #git rev-list --left-right --count $TRAVIS_BRANCH...$TRAVIS_PULL_REQUEST_SHA
else
    #####################
    # Triggered by push #
    #####################
fi
