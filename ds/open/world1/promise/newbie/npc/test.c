#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"��"HIC""BLK"�F"HIW"�a"HIC""BLK"�a"NOR"�J�f"NOR);
  set ("long", @LONG
�b�j�Ѫ��ǻ����A���b�����s���@�B�A�������H�xŸ���媺�a
��A�N�O�o�w�u���F�a�a�v�A�b�o���۵����|�ѳ��Ȫ��հ��|�աA����
�F���ۥ|�ؤ��P�S�誺���O�A�O�Hť�D�N���g���d�U�N���C
LONG
);
  set("exits", ([
  "enter" : __DIR__"enter",
  "down" : "/open/world1/cominging/purple_sun/4f4",
  ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
 }
 
int valid_leave(string dir)
{
object ob;
        if(dir=="enter")
                 message("world:world1:vision",
HIW"\n\t"+ob->name(1)+"�b"+NATURE_D->game_time(temp)+" "HIR"���J�F���F�a�a���"NOR,users());

        return ::valid_leave(me,dir);
}
