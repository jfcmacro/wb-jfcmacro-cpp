#include "ListDialog.h"
#include "EditDialog.h"

ListDialog::ListDialog() : QDialog() {
  ui.setupUi(this);

  connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addItem()));
  connect(ui.editButton, SIGNAL(clicked()), this, SLOT(editItem()));
  connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
}

void
ListDialog::addItem() {
  EditDialog dlg(this);

  if (dlg.exec() == QDialog::Accepted)
    ui.list->addItem(dlg.name() + " -- " + dlg.number());
}

void
ListDialog::deleteItem() {
  delete ui.list->currentItem();
}

void
ListDialog::editItem() {
  if (!ui.list->currentItem()) return;

  QStringList parts = ui.list->currentItem()->text().split("--");
  EditDialog dlg(this);
  dlg.setName(parts[0].trimmed());
  dlg.setNumber(parts[1].trimmed());

  if (dlg.exec() == QDialog::Accepted)
    ui.list->currentItem()->setText(dlg.name() + " -- " + dlg.number());
}
