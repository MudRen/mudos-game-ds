#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�p��"NOR);
 set("long",@LONG
�o�̧j�ۧN�檺���A���T���A�}�l�o�ݡA�o�̦��G�U�ӷU�S
���H�F�A�u���@�Ѯ��ƪ��𮧡A�[�W�e��S�n�����r�~�H�S���n 
���A���A�}�lı�o�U�ӷU���ƤF�C
LONG
    );

       set("exits",([
       "north":__DIR__"town29", 
       "west":__DIR__"town9",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

