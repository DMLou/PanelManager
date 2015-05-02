# Panel Manager

This is an application that can be used to track panels for a convention, such
as an anime or gaming convention.

## Status

The code is very raw at this point. The repo basically only exists to serve as a
backup to what I'm working on. This is also a spare-time project.

## Technologies Used

This is meant to be a cross-platform product that runs on Windows, Mac, and
Linux.

The UI is built in Qt and designed using in QtCreator. That is also why the
application uses a QtCreator project file instead of a CMake file or any other
solution. It was the quickest and easiest way for me to draw the UI as
hand-coding UI code is way too tedious and I'd rather not do so after doing it
quite a bit over the years.

The data format is a SQLite database as it is cross-platform, more or less
standard, light-weight, and contains all the functionality I need for this
application. It can also be viewed/modified/etc. with standard SQLite tools as
necessary for repair or advanced use that may not be directly supported by the
UI.

## License

This code is released under the Mozilla Public License version 2.0.

Why the MPL? Well, there are aspects about both the GPL and BSD-style licenses
that I like and the MPL seems to be a good compromise between them. Use my code
anyway you want, but if you make improvements/changes/etc. to my code, you need
to open source those changes in kind. If you use it unmodified in your project,
you don't need to do squat, basically.

For more details, read the license yourself: https://www.mozilla.org/MPL/2.0/