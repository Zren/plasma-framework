/*
 * Copyright(C) 2009 Adenilson Cavalcanti <adenilson.silva@idnt.org.br>*
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "animator.h"
#include "private/animator_p.h"

#include <kdebug.h>

#include "animations/animation.h"
#include "animations/fade_p.h"
#include "animations/grow_p.h"
#include "animations/pulser_p.h"
#include "animations/rotation_p.h"
#include "animations/slide_p.h"
#include "animations/rotationstacked_p.h"
#include "animations/geometry_p.h"
#include "animations/zoom_p.h"

namespace Plasma
{

Plasma::Animation* Animator::create(Animator::Animation type, QObject *parent)
{
    Plasma::Animation *result = 0;

    switch (type) {
    case FadeAnimation:
        result = new Plasma::FadeAnimation(parent);
        break;

    case GrowAnimation:
        result = new Plasma::GrowAnimation(parent);
        break;

    case PulseAnimation:
        result = new Plasma::PulseAnimation(parent);
        break;

    case RotationAnimation:
        result = new Plasma::RotationAnimation(parent);
        break;

    case RotationStackedAnimation:
        result = new Plasma::RotationStackedAnimation(parent);
        break;

    case SlideAnimation:
        result = new Plasma::SlideAnimation(parent);
        break;

    case GeometryAnimation:
        result = new Plasma::GeometryAnimation(parent);
        break;

    case ZoomAnimation:
        result = new Plasma::ZoomAnimation(parent);
        break;

    default:
        kDebug() << "Unsupported animation type.";
    }

    return result;
}

} // namespace Plasma

#include <animator.moc>

