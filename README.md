# Mupen64Plus-Qt [![Build Status](https://travis-ci.org/dh4/mupen64plus-qt.svg?branch=master)](https://travis-ci.org/dh4/mupen64plus-qt)

A basic cross-platform launcher. This was adapted from CEN64-Qt to work with Mupen64Plus.

A discussion thread can be found [here](http://www.emutalk.net/threads/54976-Mupen64Plus-Qt).

![Mupen64Plus-Qt Grid View](https://dl.dropboxusercontent.com/u/232085155/mupen64plus-qt/github.jpg)


## Getting Mupen64Plus-Qt

### Stable Builds

Stable releases can be found on the [releases](https://github.com/dh4/mupen64plus-qt/releases) page.

### Development Builds

Automatic builds of the latest git commit can be downloaded here:  
Linux: [mupen64plus-qt_linux_git-latest.tar.gz](https://s3.amazonaws.com/dh4/mupen64plus-qt/latest/mupen64plus-qt_linux_git-latest.tar.gz)  
Windows: [mupen64plus-qt_win_git-latest.zip](https://s3.amazonaws.com/dh4/mupen64plus-qt/latest/mupen64plus-qt_win_git-latest.zip)  
OSX: [mupen64plus-qt_osx_git-latest.dmg](https://s3.amazonaws.com/dh4/mupen64plus-qt/latest/mupen64plus-qt_osx_git-latest.dmg)

Be aware that these may contain bugs not present in the stable releases.


### Building (Linux)

You'll need to make sure you have qmake, g++, the Qt development libraries and the QuaZIP development files installed. On Debian/Ubuntu, this can be accomplished by:

```
# apt-get install qt5-qmake g++ qtbase5-dev libquazip-qt5-dev libqt5sql5-sqlite
```

Once the needed packages are installed, create the Makefile with qmake and then build with make:

```
$ qmake
$ make
```

If qmake returns "qmake: could not find a Qt installation of ''", you can try running `QT_SELECT=qt5 qmake` or `/usr/lib/x86_64-linux-gnu/qt5/bin/qmake`. Some distributions also contain a `qmake-qt5` symlink.

##### Building with Qt4

Install the Qt4 dependencies instead. On Debian/Ubuntu:

```
# apt-get install qt4-qmake g++ libqt4-dev libquazip-dev libqt4-sql-sqlite
```

Then create the Makefile with qmake and build with make:

```
$ qmake-qt4
$ make
```

##### Compiling QuaZIP statically

You also have the option to compile QuaZIP statically. Download the QuaZIP sources from Sourceforge. Place the contents of `quazip-<version>/quazip/` in `quazip/` within the project directory. Then run:

```
$ qmake CONFIG+=linux_quazip_static
$ make
```

You will see warnings after the qmake step if the QuaZIP sources are in the wrong place.


## First Launch and Setup

Mupen64Plus-Qt contains code that attempts to auto-detect a Mupen64Plus installation. These settings are located at Settings->Configure->Paths. See below for a per-OS description of this and what to do if Mupen64Plus is not auto-detected.

#### Linux

Mupen64Plus-Qt looks within common locations distributions place the mupen64plus binary, plugin libraries and data files. If any of these aren't found, obtain the Mupen64Plus package for you distribution and peek inside to see where the files are placed (or use a utility such as find or mlocate).

The plugin directory should contain mupen64plus-video-rice.so, mupen64plus-video-glide64mk2.so, etc. The data directory should contain mupen64plus.ini. You should be able to find the executable by running `which mupen64plus`.

#### Windows

It's best to place mupen64plus-qt.exe within the same folder as mupen64plus-ui-console.exe (mupen64plus.exe before version 2.5) as Mupen64Plus-Qt looks in the same directory it's running from to try and find the executable, plugins and data files.

If you place it somewhere else, set the plugin directory and data directory to the same folder containing mupen64plus-ui-console.exe.

#### OSX

Mupen64Plus-Qt looks for mupen64plus.app within the same directory where Mupen64Plus-Qt.app is placed.

If you place it somewhere else, simply select mupen64plus.app as the executable and it will autofill the plugin and data directory settings for you (these are within mupen64plus.app).


## ROM Collection

You can specify ROM directories under Settings->Configure->Paths. Mupen64Plus-Qt will search for any .z64, .v64 or .n64 files within these directories and also check within .zip files. After adding or removing directories to this list, it will automatically refresh your ROM list. You can manually refresh your list with File->Refresh List.

Mupen64Plus-Qt contains three options for displaying your ROMs: a table view, grid view and list view. The view can be changed under Settings->Layout. These can be configured under Settings->Configure.


## Game Information

Mupen64Plus-Qt supports downloading game information and cover images from [thegamesdb.net](http://thegamesdb.net/). This can be enabled under Settings->Configure->Other. It's recommended you have the data directory set (under Paths) before using this. Once enabled, you'll need to refresh your ROMs list to download the information. Afterwards, images and other information about the game can be added to the layouts.

#### Updating Game Information

If a game is not found or is incorrect, Mupen64Plus-Qt supports refreshing information for a single ROM. Just select the ROM and go to File->Download/Update Info. From here you can enter a different search or the specific ID of the game (from the URL of the game on thegamesdb.net).


#### Deleting Game Information

You can delete the game information fetched from TheGamesDB by using File->Delete Current Info. Note that if you are deleting a game's information because the game doesn't exist on TheGamesDB and Mupen64Plus-Qt pulled the information for different game, it's better to create an account on TheGamesDB and add the game so other users can benefit as well.

This will cause Mupen64Plus-Qt to not update the information for this game until you force it with File->Download/Update Info


#### Manually Updating Information

If desired, you can also manually update the information from TheGamesDB. Note that if any information is incorrect, it's best to create an account on TheGamesDB and fix it there so all users can benefit.

The information cache can be found here:

Linux: /home/\<user\>/.local/share/mupen64plus-qt/cache/\<MD5 of game\>/  
Windows: cache folder in same directory as executable -> MD5 of game  
OSX: /Users/\<user\>/Library/Application Support/mupen64plus-qt/cache/\<MD5 of game\>/

You can find the MD5 of a game by using the table or list view and adding "MD5" to the current information.

Edit data.xml with a text editor and replace any information you want to change. You can also replace boxart-front.{jpg,png} with an image of your choosing.


## Mupen64Plus Config Editor

Mupen64Plus-Qt contains an editor with syntax highlighting for mupen64plus.cfg. To use it, make sure you have your config directory set under Settings->Configure->Paths. Mupen64Plus-Qt should auto-detect this setting for you. If it doesn't, the default location is:

Linux: /home/\<user\>/.config/mupen64plus/  
Windows: C:/Users/\<user\>/AppData/Roaming/Mupen64Plus/  
OSX: /Users/\<user\>/.config/mupen64plus/


## Mupen64Plus Log

Mupen64Plus-Qt allows you to view the output from the Mupen64Plus console UI. Select Emulation->View Log after Mupen64Plus has quit to see the output from the last run.


## Configuration File

Mupen64Plus-Qt saves its settings to a text file. If for some reason you would like to modify this, it's contained at the following locations:  
Linux: /home/\<user\>/.config/mupen64plus/mupen64plus-qt.conf  
Windows: mupen64plus-qt.ini within the same directory as the executable  
OSX: /Users/\<user\>/Library/Preferences/com.mupen64plus.mupen64plus-qt.plist


## Comparison to Console UI

Mupen64Plus-Qt utilizes the console UI to launch games. It contains support for most of the command line parameters. These can be viewed by running Mupen64Plus from a terminal with the --help parameter or [here](https://code.google.com/p/mupen64plus/wiki/UIConsoleUsage).

See below for how each parameter is used within Mupen64Plus-Qt:

##### --noosd/--osd

One or the other is sent to Mupen64Plus based on whether the "On Screen Display" checkbox is checked under the graphics tab.

##### --fullscreen/--windowed

Similarly, one or the other is sent based on the "Fullscreen" checkbox underneath the graphics tab.

##### --resolution

This can be configured with the "Resolution" combo box underneath the graphics tab. The list is generated based on common resolutions smaller than your current desktop resolution. If you require a resolution not in the list, just set the "default" option which will not send the --resolution parameter to Mupen64Plus (Mupen64Plus will read from whatever setting is within its configuration file in this case).

##### --configdir

This is configured under the paths tab. This is entirely optional, but allows you to specific a different directory to load the mupen64plus.cfg file from (useful if you want to say, load different input settings at different times).

##### --datadir

This is set underneath the paths tab. Mupen64Plus-Qt will also make use of the data directory setting to load the GoodName text and other information from the mupen64plus.ini file, so make sure this directory contains that file. It's usually /usr/share/mupen64plus on Linux or the same directory as the executable on Windows.

##### --plugindir

The plugin directory is usually /usr/lib/mupen64plus or within the same directory as the executable on Windows. Mupen64Plus-Qt also makes use of this directory setting to populate the options on the plugins tab (you must click Ok first before they will populate).

##### --gfx/--audio/--input/--rsp

These are configured under the plugins tab once the plugin directory has been set.

##### ---emumode

This is configured under the emulation tab.

##### --saveoptions/--nosaveoptions

One or the other is sent to Mupen64Plus based on the "Save Options" checkbox underneath the other tab. If --saveoptions is set, then Mupen64Plus will save whatever settings are passed to it into its configuration file (mupen64plus.cfg)

#### Additional Parameters (Cheat Support)

Mupen64Plus-Qt also supports specifying additional parameters under Settings->Configure->Other->Additional Parameters. You can specify any other parameters that the console UI supports here.

The main use of this is specifying cheats. For example, filling this with `--cheats 'list'` will allow you to double click on a ROM and then view the log for a list of cheats for that game (remove it to be able to launch games again). You can then specify what cheats you want with `--cheats 1,2-1,3`, etc.

Be aware that if this contains anything that Mupen64Plus doesn't support, the emulator will not be able to launch.


## Linux: GLideN64 Workaround

Mupen64Plus-Qt contains support for [this](https://github.com/gonetz/GLideN64/issues/454#issuecomment-126853972) workaround for GLideN64 on Linux. There is no graphical option for this as it's more of a hack and should be fixed on GLideN64's end. Edit your configuration file at ~/.config/mupen64plus/mupen64plus-qt.conf and add "forcegl33=true" under [Other].
