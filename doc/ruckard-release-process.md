# update (commit) version in sources
* src/clientversion.h

# tag version in git

```
git tag -a v1.4.7.2
git tag -a v1.4.7.2-mini
```
# write release notes.
git shortlog helps a lot:
```
git shortlog --no-merges v1.4.7.1..
```
# Prerequisites
You already met pre-requisites to build the different binaries on your build machine.

# AMD64 build
## Ubuntu standard - magid and m-wallet build - AMD64
Bash is assumed to be used.
```
# Build
export MAGI_VERSION="1.4.7.2"
export MAGI_SRC_VERSION="v${MAGI_VERSION}"
export MAGI_SRC_REPO="https://github.com/ruckard/magi"
export MAGI_SRC_BUILD_DIR="/tmp/magi-build-magid-${MAGI_SRC_VERSION}-amd64"
export MAGI_RELEASE_BASEDIR="${MAGI_SRC_BUILD_DIR}/ruckard-release"
export MAGI_RELEASE_DIR="${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}"
mkdir -p ${MAGI_SRC_BUILD_DIR}
git clone ${MAGI_SRC_REPO} ${MAGI_SRC_BUILD_DIR} -b ${MAGI_SRC_VERSION}
cd ${MAGI_SRC_BUILD_DIR}/src
make -f makefile.unix
cd ..
qmake "USE_UPNP=1" "USE_DBUS=1"
make
# Prepare release
mkdir -p ${MAGI_RELEASE_DIR}/bin/64
mkdir -p ${MAGI_RELEASE_DIR}/doc
# Release
cp ${MAGI_SRC_BUILD_DIR}/m-wallet ${MAGI_RELEASE_DIR}/bin/64
cp ${MAGI_SRC_BUILD_DIR}/src/magid ${MAGI_RELEASE_DIR}/bin/64
cp ${MAGI_SRC_BUILD_DIR}/doc/release-notes.md ${MAGI_RELEASE_DIR}/doc
cp ${MAGI_SRC_BUILD_DIR}/README.md ${MAGI_RELEASE_DIR}
# Pack release
tar -C ${MAGI_RELEASE_BASEDIR} -czf ${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}.tar.gz m-wallet-${MAGI_VERSION}
echo "${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}.tar.gz is ready!"
```
# AARCH64 standard build
## Ubuntu standard - magid and m-wallet build - AARCH64
Bash is assumed to be used.
```
export MAGI_VERSION="1.4.7.2"
export MAGI_SRC_VERSION="v${MAGI_VERSION}"
export MAGI_SRC_REPO="https://github.com/ruckard/magi"
export MAGI_SRC_BUILD_DIR="/tmp/magi-build-magid-${MAGI_SRC_VERSION}-aarch64"
export MAGI_RELEASE_BASEDIR="${MAGI_SRC_BUILD_DIR}/ruckard-release"
export MAGI_RELEASE_DIR="${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}"
mkdir -p ${MAGI_SRC_BUILD_DIR}
git clone ${MAGI_SRC_REPO} ${MAGI_SRC_BUILD_DIR} -b ${MAGI_SRC_VERSION}
cd ${MAGI_SRC_BUILD_DIR}/src
make -f makefile.unix xCPUARCH=aarch64
cd ..
qmake "USE_UPNP=1" "USE_DBUS=1"
make
# Prepare release
mkdir -p ${MAGI_RELEASE_DIR}/bin/64
mkdir -p ${MAGI_RELEASE_DIR}/doc
# Release
cp ${MAGI_SRC_BUILD_DIR}/m-wallet ${MAGI_RELEASE_DIR}/bin/64
cp ${MAGI_SRC_BUILD_DIR}/src/magid ${MAGI_RELEASE_DIR}/bin/64
cp ${MAGI_SRC_BUILD_DIR}/doc/release-notes.md ${MAGI_RELEASE_DIR}/doc
cp ${MAGI_SRC_BUILD_DIR}/README.md ${MAGI_RELEASE_DIR}
# Pack release
tar -C ${MAGI_RELEASE_BASEDIR} -czf ${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}.tar.gz m-wallet-${MAGI_VERSION}
echo "${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}.tar.gz is ready!"
```

# AARCH64 mini build
## Ubuntu mini - magid and m-wallet build - AARCH64
Bash is assumed to be used.
```
export MAGI_VERSION="1.4.7.2-mini"
export MAGI_SRC_VERSION="v${MAGI_VERSION}"
export MAGI_SRC_REPO="https://github.com/ruckard/magi"
export MAGI_SRC_BUILD_DIR="/tmp/magi-build-magid-${MAGI_SRC_VERSION}-aarch64-mini"
export MAGI_RELEASE_BASEDIR="${MAGI_SRC_BUILD_DIR}/ruckard-release"
export MAGI_RELEASE_DIR="${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}"
mkdir -p ${MAGI_SRC_BUILD_DIR}
git clone ${MAGI_SRC_REPO} ${MAGI_SRC_BUILD_DIR} -b ${MAGI_SRC_VERSION}
cd ${MAGI_SRC_BUILD_DIR}/src
make -f makefile.unix xCPUARCH=aarch64
cd ..
qmake "USE_UPNP=1" "USE_DBUS=1"
make
# Prepare release
mkdir -p ${MAGI_RELEASE_DIR}/bin/64
mkdir -p ${MAGI_RELEASE_DIR}/doc
# Release
cp ${MAGI_SRC_BUILD_DIR}/m-wallet ${MAGI_RELEASE_DIR}/bin/64
cp ${MAGI_SRC_BUILD_DIR}/src/magid ${MAGI_RELEASE_DIR}/bin/64
cp ${MAGI_SRC_BUILD_DIR}/doc/release-notes.md ${MAGI_RELEASE_DIR}/doc
cp ${MAGI_SRC_BUILD_DIR}/README.md ${MAGI_RELEASE_DIR}
# Pack release
tar -C ${MAGI_RELEASE_BASEDIR} -czf ${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}.tar.gz m-wallet-${MAGI_VERSION}
echo "${MAGI_RELEASE_BASEDIR}/m-wallet-${MAGI_VERSION}.tar.gz is ready!"
```

# UPLOAD

Upload zips and tgzs to SourceForge

# NEWS

* Write piece of news to BitcoinTalk thread.
* Tell someone from 'The Magi Lounge' discord to update the #announcements channel.

# TODO
* Check doc/release-process.txt to improve this release process.
