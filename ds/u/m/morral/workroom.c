#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIC"���§Q���a��"NOR);
        set("long", @LONG
�A�Ө�F�@�ӫ��u�����ж��Aı�o���§Q�b�o�L���~���p����
����l�A�u�O�D�`�ξA.���M�ɭȮL��,���L��Ԩä����u��
�a�a�����˼��㴻��.�@�}�}���L���ƹL�L�줧��,�ϩ��O�[
��������M������������H���ֽ��~���εΪA�A.
LONG
); // ���ԭz
 set("exits", ([  //���ж��s�����X�f��V���ɮ�
    "luky" : "/u/l/luky/workroom",
"shengsan": "/u/s/shengsan/workroom",
"wiz": "/d/wiz/hall1",
"meet":"/open/world3/meetroom",
"arch":"/d/wiz/hall6",
//"iceland":"/u/m/morral/iceland/port1",
]));
set("light",1);
set("valid_startroom",1);  
set("no_fight",1);
set("no_magic",1);
set("objects",([
]));
        set("no_clean_up", 0);
setup();
        replace_program(ROOM);
}                                  
