/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __qtListDelegate_h
#define __qtListDelegate_h

#include "qtAbstractListDelegate.h"

class QListWidgetItem;

class QTE_EXPORT qtListDelegate : public qtAbstractListDelegate
{
  Q_OBJECT

public:
  qtListDelegate(QObject* parent = 0);
  virtual ~qtListDelegate();

  virtual void setModelData(QWidget* editor, QAbstractItemModel*,
                            const QModelIndex&) const;
  virtual void updateEditorGeometry(QWidget* editor,
                                    const QStyleOptionViewItem&,
                                    const QModelIndex&) const;

protected:
  using qtAbstractListDelegate::setModelData;

  virtual QWidget* createListEditor(QWidget* parent) const;
  virtual QListWidgetItem* createListItem(const QString& name,
                                          const QVariant& data) const;
  virtual void setListEditorData(QWidget* editor, const QVariant&) const;

private:
  Q_DISABLE_COPY(qtListDelegate);
};

#endif
