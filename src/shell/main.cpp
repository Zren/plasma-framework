/*
 *  Copyright 2012 Marco Martin <mart@kde.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <QApplication>
#include <QtQuick/QQuickView>
#include <QtCore/QDebug>
//#include "svg.h"

#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocalizedstring.h>

#include <Plasma/Containment>

#include "desktopcorona.h"
#include "shellpluginloader.h"


static const char description[] = "Plasma2 library tests";
static const char version[] = "1.0";

int main(int argc, char** argv)
{

    KAboutData aboutData("testplasma2", QByteArray(), qi18n("Plasma2 test app"),
                         version, qi18n(description), KAboutData::License_GPL,
                         qi18n("Copyright 2012, The KDE Team"));
    aboutData.addAuthor(qi18n("Marco Martin"),
                        qi18n("Author and maintainer"),
                        "mart@kde.org");
    KCmdLineArgs::init(argc, argv,
                       "testplasma2", "",
                       ki18n("Plasma2 test app"),
                       version);

    QApplication app(argc, argv);

    Plasma::PluginLoader::setPluginLoader(new ShellPluginLoader);
    DesktopCorona *corona = new DesktopCorona();
    corona->loadLayout();
    if (corona->containments().isEmpty()) {
        corona->loadDefaultLayout();
    }
    corona->checkScreens();
    
    return app.exec();
}
