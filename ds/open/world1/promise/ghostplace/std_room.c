#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"���F�a�a"NOR"�J�f"NOR);
  set ("long", "
    �b�j�Ѫ��ǻ����A���b�����s���@�B�A�������H�xŸ���媺�a��A�N
�O�o�w�u���F�a�a�v�A�b�o���۵����|�ѳ��Ȫ��հ��|�աA�����F���ۥ|��
���P�S�誺���O�A�O�Hť�D�N���g���d�U�N���C\n 
");
  set("exits", ([
  "enter" : __DIR__"f1",
  "down" : "/open/world1/cominging/purple_sun/4f4",
  ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
 }
 int valid_leave(object me, string dir)
{

        string gender;
        gender=me->query("gender");
        if ( gender=="�k��" ) gender="�֫L";
        if ( gender=="�k��" ) gender="�L�k";
        if ( me->query("age") > 50 ) gender="�ѫe��";
        
        if( dir=="enter" )
        {
 message("world:world1:vision",
HIW"\n\t"+me->query("name")+HIR"���J�F���F�a�a�A"HIG"�հ��|��"HIR"��D�G\n
"HIY"\t\t�o��"HIW+gender+HIY"�u�O�x�j�A���J�ڭ̪��T�a�I�I\n
"HIG"\t�@�n�O�U�A�Ҧ��L�ìB�F�L���A�ǳ����ԡI�I\n\n"NOR,users());
                                            
     }
        return ::valid_leave(me, dir);
}



