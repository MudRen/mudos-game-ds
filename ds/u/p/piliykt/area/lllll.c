inherit ROOM;
void create()
{
set("short","�s�_");
set("long", @LONG
�A�����b�s�_��, �o�̥ѩ�O�s�_, �ҥH�Żثܤp, �]�\�O�Ů𤣬y
�q, ���Aı�o�o�̥i��O�@�y���s, �]���o�̪��ū׼���A�����F, �A��
���Q���I�k���o��.
LONG
);
set("outdoors","heat");
set("exits", ([ 
                "south"  : __DIR__"tree5.c",
                           ]));
set("objects",([
__DIR__"npc/master_2.c" : 1,
              ]) );
setup();
        
}

