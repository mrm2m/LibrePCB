/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "initializeworkspacewizard.h"

#include "initializeworkspacewizard_chooseimportversion.h"
#include "ui_initializeworkspacewizard.h"

/*******************************************************************************
 *  Namespace
 ******************************************************************************/
namespace librepcb {
namespace application {

/*******************************************************************************
 *  Constructors / Destructor
 ******************************************************************************/

InitializeWorkspaceWizard::InitializeWorkspaceWizard(workspace::Workspace& ws,
                                                     QWidget* parent) noexcept
  : QWizard(parent), mWorkspace(ws), mUi(new Ui::InitializeWorkspaceWizard) {
  mUi->setupUi(this);

  // add pages
  setPage(Page_ChooseImportVersion,
          new InitializeWorkspaceWizard_ChooseImportVersion());

  // set header logo
  setPixmap(WizardPixmap::LogoPixmap, QPixmap(":/img/logo/48x48.png"));
}

InitializeWorkspaceWizard::~InitializeWorkspaceWizard() noexcept {
}

/*******************************************************************************
 *  Getters
 ******************************************************************************/

/*******************************************************************************
 *  Inherited from QWizard
 ******************************************************************************/

int InitializeWorkspaceWizard::nextId() const {
  switch (currentId()) {
    case Page_ChooseImportVersion: {
      return -1;
    }
    default: { return -1; }
  }
}

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace application
}  // namespace librepcb
