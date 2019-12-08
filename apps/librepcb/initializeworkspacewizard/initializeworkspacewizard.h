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

#ifndef LIBREPCB_APPLICATION_INITIALIZEWORKSPACEWIZARD_H
#define LIBREPCB_APPLICATION_INITIALIZEWORKSPACEWIZARD_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include <librepcb/common/fileio/filepath.h>

#include <QtCore>
#include <QtWidgets>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

namespace workspace {
class Workspace;
}

namespace application {

namespace Ui {
class InitializeWorkspaceWizard;
}

/*******************************************************************************
 *  Class InitializeWorkspaceWizard
 ******************************************************************************/

/**
 * @brief The InitializeWorkspaceWizard class
 */
class InitializeWorkspaceWizard final : public QWizard {
  Q_OBJECT

  enum PageId {
    Page_ChooseImportVersion,
  };

public:
  // Constructors / Destructor
  explicit InitializeWorkspaceWizard(workspace::Workspace& ws,
                                     QWidget* parent = nullptr) noexcept;
  InitializeWorkspaceWizard(const InitializeWorkspaceWizard& other) = delete;
  ~InitializeWorkspaceWizard() noexcept;

  // Inherited from QWizard
  int nextId() const override;

  // Operator Overloadings
  InitializeWorkspaceWizard& operator=(const InitializeWorkspaceWizard& rhs) =
      delete;

private:
  workspace::Workspace&                         mWorkspace;
  QScopedPointer<Ui::InitializeWorkspaceWizard> mUi;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace application
}  // namespace librepcb

#endif  // LIBREPCB_APPLICATION_INITIALIZEWORKSPACEWIZARD_H
