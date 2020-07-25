// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#include <noggit/ui/About.h>
#include <noggit/TextureManager.h>



#include <QIcon>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QDate>
#include <QLocale>

namespace noggit
{
  namespace ui
  {
    about::about(QWidget* parent)
      : QDialog(parent)
    {
      setWindowIcon(QIcon(":/icon"));
      setWindowTitle("关于");

      //! \todo make nice looking again, I don't care currently
      new QVBoxLayout (this);

      auto icon (new QLabel (this));
      icon->setPixmap (render_blp_to_pixmap ("interface/icons/inv_potion_83.blp"));
      layout()->addWidget (icon);
      //! \todo was Skurri32
      layout()->addWidget (new QLabel ("Noggit Studio\n", this));
      layout()->addWidget (new QLabel ("  1. 修复了一些崩溃\n"
                                       "  2. 汉化了大部分内容\n", this)
                          );

      QDate date = QLocale(QLocale::C).toDate(QString(__DATE__).simplified(), "MMM dd yyyy");
      layout()->addWidget (new QLabel (("咸蛋汉化版" STRPRODUCTVER "  ") + date.toString(Qt::ISODate), this));
      layout()->addWidget (new QLabel ("魔兽世界版权归暴雪娱乐所有", this));
    }
  }
}
