#include <room.h>
inherit ROOM;

void create()
{
 set("short","�}���p��");
        set("long",@LONG
�@�����t���o�O�M�@�i�}�ª����A�n�����O�����ӱ���A���y�W�A
�����q����]�i�Ӫ��B��b�a�𪺮Ѭ[�W�O�O���s�A��T�i�p����ê��\
�ۡA���۳o�̪��\�]�ݤU�h�A���M�o�{�A���}�U�����@�Ӥj�۪��T���W��
��Ӥj�K���R�R�{ģ�ۨ����������A�n���D���۪��U�������ΦM���A��M
�@�}�H���j�J�A���A���T�򰩮��M�C
LONG
        );

         set("exits", ([
         "south": __DIR__"hole_out",
       "down":__DIR__"hole_2",
         ]));
        create_door("down","�۪�","up",DOOR_CLOSED);

        set("objects",([
              __DIR__"npc/pan-en" : 1,
          ]) );
        set("light", 1);
        setup();
        replace_program(ROOM);

 }