#include <QWidget>
#include <QShortcut>
#include <QPainter>
#include <QTimer>
#include <QScrollArea>
#include <QMessageBox>
#include <QColor>
#include <QMouseEvent>
#include "mediator.h"

#ifndef EDITORTILEPALLETE
    #include "editortilepallete.h"
#endif

#ifndef FILE_GAME
	#include "../file/format.h"
#endif

extern int palleteX;
extern int palleteY;
extern Mediator *dataExchanger;


struct pointElement{
   int palleteX, palleteY, type;
};

class EditorArea : public QWidget
{
  Q_OBJECT

public:
  // methods
  EditorArea(QWidget *parent = 0);
  void setInfoPalette(EditorTilePallete *temp_pallete);

  // variables
  QWidget *myParent;

private:
  void removeNpcFromMap(int, int);

  // variables
  int link_pos_x;
  int link_pos_y;
  int link_map_origin;
  int link_size;


protected:
  // methods
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent * event);
  void mouseReleaseEvent(QMouseEvent * event);
  void mouseMoveEvent(QMouseEvent *event);

  // variables
  int temp;
  int editor_selectedTileX, editor_selectedTileY;
  int tempX, tempY;
  EditorTilePallete *my_pallete;
  void fill_area();

  int map_backup_n;
  bool mouse_released;

//signals:
//     void save();

public slots:
   void changeTile();
   void saveGame(int game_n);
   void addObjectToMap(int, int);



};
