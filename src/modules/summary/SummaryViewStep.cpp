/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2014-2015 Teo Mrnjavac <teo@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is Free Software: see the License-Identifier above.
 *
 */

#include "SummaryViewStep.h"

#include "SummaryPage.h"

CALAMARES_PLUGIN_FACTORY_DEFINITION( SummaryViewStepFactory, registerPlugin< SummaryViewStep >(); )

SummaryViewStep::SummaryViewStep( QObject* parent )
    : Calamares::ViewStep( parent )
    , m_widget( new SummaryPage( this ) )
    , m_config( new Config( this ) )
{
    emit nextStatusChanged( true );
}


SummaryViewStep::~SummaryViewStep()
{
    if ( m_widget && m_widget->parent() == nullptr )
    {
        m_widget->deleteLater();
    }
    delete m_config;
}


QString
SummaryViewStep::prettyName() const
{
    return tr( "Summary" );
}


QWidget*
SummaryViewStep::widget()
{
    return m_widget;
}


bool
SummaryViewStep::isNextEnabled() const
{
    return true;
}


bool
SummaryViewStep::isBackEnabled() const
{
    return true;
}


bool
SummaryViewStep::isAtBeginning() const
{
    return true;
}


bool
SummaryViewStep::isAtEnd() const
{
    return true;
}


Calamares::JobList
SummaryViewStep::jobs() const
{
    return {};
}


void
SummaryViewStep::onActivate()
{
    m_config->init();
    m_widget->onActivate();
}


void
SummaryViewStep::onLeave()
{
    m_widget->onLeave();
}
