#!/usr/bin/env bash

# set shell settings (see https://sipb.mit.edu/doc/safe-shell/)
set -euv -o pipefail

# extract debug symbols
objcopy --only-keep-debug ./build/install/opt/bin/librepcb \
  ./artifacts/nightly_builds/librepcb-nightly-linux-x86_64.debug
objcopy --only-keep-debug ./build/install/opt/bin/librepcb-cli \
  ./artifacts/nightly_builds/librepcb-cli-nightly-linux-x86_64.debug

# run linuxdeployqt to bundle Qt libs
linuxdeployqt "./build/install/opt/bin/librepcb-cli" -bundle-non-qt-libs -always-overwrite
linuxdeployqt "./build/install/opt/bin/librepcb" -bundle-non-qt-libs -always-overwrite

# copy to artifacts
cp -r "./build/install/opt" "./artifacts/nightly_builds/librepcb-nightly-linux-x86_64"
