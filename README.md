Ruckard's Coin Magi Corner
====================

Introduction
------------
While the [magi community](https://www.xmg.network/) finds a proper developer who knows how to rebase magi code on latest bitcoin core version I will be tinkering with the old code and improving it a bit.

Issues are welcome
------------------
You are welcome to open [issues](https://github.com/ruckard/magi/issues) but don't get mad at me if I ignore your requests.

What you can expect
-------------------
In addition to fix bugs and adapt the software to newest systems I'll also try to release some newer versions although if nobody helps me on how to cross-compile them and test them, well, you would find out that you only have the linux release as the last version.

About latest upstream version
------------------------------
The latest upstream version was 1.4.6.2 version from 16 May 2018.
If there's a newer version on the [releases](https://github.com/ruckard/magi/releases) section then it's probably a version from me.

Can you help me on installing/using this?
-----------------------------------
Short answer: No, I'm busy developing this or doing stuff IRL.

Long answer:
First of all check the documentation found on [https://www.xmg.network/](https://www.xmg.network/). Please complain to them if the documentation is not good enough. Also check for help on their discord server. [Latest The Magi Lounge Discord invitation link](https://discord.gg/EPHw749). If the link is not valid please search for it on [https://www.xmg.network/](https://www.xmg.network/).

Just check the documentation (README and INSTALL files) found on the branch you are using or in the release you are downloading.
If the documentation can be improved please open a new [issue](https://github.com/ruckard/magi/issues).



Technical stuff
====================

* Development branches will be named as dev/branchname . Be warned that I can force-push commits to them.
* Stable branches, if there are any, would be the numbered ones (1.x.y.z) which represent the newest versions.
* The default branch of this repo is ruckard-corner so that you can see this special message. If you are forking this repo please remove this ruckard-corner branch from your own forked repo.
* master branch is not modified so that it matches upstream repo, and, well, because it might be used as the stable branch much much later in the future. Who knows.
* upstream branch matches upstream repo.
* [WillWammer magi2.0 repo](https://github.com/WillWammer/magi2.0) attempted to port the codebase to latest Bitcoin core version but I don't think they have finished the port. You will find the 2020 May snapshot of their work here in the dev/willwammer-master branch just in case it is useful in the future.
* If you are a developer from the future willing to continue the magi project and I am not reachable I have already explained what you have to do above but I think it was rather cryptic. So here it goes:
    - Clone the full repo
    - Remove the ruckard-corner branch but after having saved this updated README.
    - Find if there's something interesting in the dev/ branches. You might want to reuse some of those ideas.
    - Check for the highest numbered branch (1.x.y.z) which has an associated release. This should be your stable branch.
    - If there is a highest numbered branch (1.x.y.z) but it does not have an associated release. This might be your stable branch or not. You are on your own making that decision.
    - Good luck!



<pre>
.
.
.
.
.
.
.
.
.
.
.
.
.
</pre>

Traditional Coin Magi README
====================

Copyright (c) 2009-2012 The Bitcoin Core developers

Copyright (c) 2012-2014 The PPCoin developers

Copyright (c) 2014-2017 The Magi Core developers

Coin Magi, derived from Bitcoin and PPCoin, is released under the terms of 
the MIT license. See COPYING for more information or see 
http://opensource.org/licenses/MIT.

Intro
---------------------
Coin Magi (XMG) is an online payment system, enabling instant payments to anyone in the world without using an intermediary. Magi coins can be minted by computational devices including personal computers and portable devices through mPoW and mPoS. Magi aims at fairness, cost effective and energy efficiency during coin minting. Magi is a hybrid PoW/PoS-based cryptocurrency that integrates two mechanisms: proof-of-work (PoW) and proof-of-stake (PoS) protocols. Magi is a CPU coin. 

Features
---------------------
- mPoW, the magi's proof-of-work (PoW) protocol, in addition to required computational works to be done to deter denial of service attacks, is also a network-dependent rewarding model system. The mPoW rewards participants who solve complicated cryptographical questions not only to validate transactions but also to create new blocks in order to generate coins. The coins mined via mPoW are adjusted and balanced by two primary mechanisms: 1) stimulating network activities by issuing rewards, and 2) mitigating redundant mining sources by reducing rewards.

- The particular designed block reward system to remove the competitive nature of 
mining and offer an even playing field for anyone looking to issue coins 
without expensive equipment - offering features such as energy saving, proof of 
mining.

- mPoS, the magi's proof-of-stake (PoS) protocol, aims to achieve distributed consensus through operations in addition to mPoW. mPoS is designed such that it rejects potential attacks, for example, through accumulating a large amount of coins or offline stake time. Magi hybridizes PoW with PoS, and integrate both consensus approaches in order to acquire benefits from the two mechanisms and create a more robust payment system. mPoS particularly enhances the security of XMG's staking system that distinguishes itself from the original concept developed by PPCoin. 

Development process
---------------------

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
stable release versions of Magi.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'.

Setup
---------------------
If you are just starting to explore magi, or upgrading wallet from versions prior to v1.3.0, the following procedure is recommended:  

1) Backup wallet.dat;

2) Remove the block-chain data under the .magi (unix-like system) or Magi (OS X or Windows) folder, except for wallet.dat;

3) Download latest block-chain data from here: http://m-core.org/bin/block-chain;

4) Unzip all the contents under "m-blockchain" into the .magi or Magi folder;

5) Launch the new wallet. 

- Windows: double click to install, or unpack the files and run the wallet directly;

- Mac OS: unpack the files and copy to the Application folder, and then run the wallet directly;

- Linux: unpack the files and run the wallet directly. 

Info
---------------------
- Website: http://www.m-core.org
- Bitcointalk thread: https://bitcointalk.org/index.php?topic=735170.0
- Forum: http://www.m-talk.org/
- Freenode IRC: #magi
