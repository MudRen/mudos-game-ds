#include <ansi.h>
inherit ITEM;
void create()
{
       set_name(HIR"�m�խ߯����_��n"NOR,({"you ming book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "��");
          set("long",
              "�o�O�@����O�F�Ѵݨ��ФQ�~�������~���g��\n"
              "�����ѡA�ǻ�������@�f���z�o�H�鷥������\n"
              "���O���Y�@���]���ѡA�u�ѤU�ݯ}���ѥ֡C\n");
            }
        set("value", 0);
        set_weight(250);
        setup();
}
