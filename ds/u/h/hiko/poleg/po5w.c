#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�y�������|");
set("long",@LONG
�o�̱��ۦU���U�˪������Х��A�o�̤]�O���̫C�~���~��ҥ��w�n
�Ӫ��a��A�]���Ҧ������ҭ�}�l�@�w�n�g�L���|�����V�m��A�~���i
�ন���W��@�����ѽm���ҡA�Ӧ��a���H�̳��Q�����R�L�̪��u�@�A�]
���]�S������H�f�~�y���M���A�ӥثe�����|�Y�جO�����A�]�����b��
���n�淥���C
LONG
    );
 set("exits",([
"east":__DIR__"po5",
"north" : __DIR__"po5w-n",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             




