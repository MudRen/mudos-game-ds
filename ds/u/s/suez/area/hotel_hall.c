#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIY"��P�ȴ̤j�U"NOR);
       set("long",@LONG
�o�̬O��P�ȴ̪��j�U�A������s���a��Q���������b�b�A�x�X�X�M
�����A�C�M�D�����b�ٶ��j�e�ۡA�~���Ӫ����K���]�F�F�@�T�C�o�����M
�����G�A���O�s�����𮧫o���Aı�o�ߤ��@�����R�C�p�G���o�̦�������
�A���ۦb���A���N�u�����f�䨺����A������Q�F�C
LONG
        );

         set("exits", ([
         "out": __DIR__"hotel_f",
       "east":__DIR__"hotel_path",
         ]));

        set("objects",([

              __DIR__"npc/yen-lu-yu" : 1,
              __DIR__"npc/waiter" : 1,
          ]) );
       
        set("light",1);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
        replace_program(ROOM);
 }
