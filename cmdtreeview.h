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
#include <QTreeView>
#include <QResizeEvent>
#include <QContextMenuEvent>
#include <QAction>

class CMDTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit CMDTreeView(QWidget* parent);

protected:
    void resizeEvent(QResizeEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void createActions();

signals:
    void delTrack(int16_t);
    void delGroup(int16_t);
    void eraseDisc();
    void addGroup(QString, int16_t, int16_t);

private slots:
    void slotDelTrack();
    void slotDelGroup();
    void slotEraseDisc();
    void slotAddGroup();

private:
    QAction* mpaAddGroup;
    QAction* mpaDelGroup;
    QAction* mpaDelTrack;
    QAction* mpaEraseDisc;
};
