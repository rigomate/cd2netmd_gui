/**
 * Copyright (C) 2021 Jo2003 (olenka.joerg@gmail.com)
 * This file is part of cd2netmd_gui
 *
 * cd2netmd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cd2netmd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 */
#pragma once
#include <QObject>
#include <QAbstractItemModel>
#include <json.hpp>

class CTreeItem;

class CMDTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum class ItemRole : uint8_t
    {
        ROOT,
        DISC,
        GROUP,
        TRACK
    };

    explicit CMDTreeModel(const QString& jsonContent, QObject *parent = nullptr);
    virtual ~CMDTreeModel();

    void addTrack(const QString& title, const QString& mode, const QString& time);

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

protected:
    void setupModelData();
    nlohmann::json group(int track);
    nlohmann::json mMDJson;
    CTreeItem*  mpTreeRoot;
};

class CTreeItem
{
public:
    explicit CTreeItem(CMDTreeModel::ItemRole role, const QVector<QVariant> &data, CTreeItem *parentItem = nullptr, int iNo = -1);
    ~CTreeItem();

    void appendChild(CTreeItem *child);

    CTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    CTreeItem *parentItem();
    CMDTreeModel::ItemRole itemRole() const;
    int trackNumber() const;
    QString& title();

private:
    QVector<CTreeItem*> m_childItems;
    QVector<QVariant> m_itemData;
    CTreeItem *m_parentItem;
    CMDTreeModel::ItemRole mItRole;
    int miNumber;
    QString mTitle;
};
