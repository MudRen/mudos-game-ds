#include <ansi.h>;
#include <room.h>;
inherit __DIR__"room"; // �ɸ� - alick
void create()
{
        set("short", HIC"�������E���}["HIW"�b"HIC"]"NOR);
        set("long", @LONG
�A�����b���������E���}�A�u���o�|�g�ɬO�@�������A���⤣������
�A�b�}�}�@�����������A���ۤ@��վv���C�����@���k�A�@���b�o������
��¶�۴N�O�񤣤F�o�����Ǥ��ءA�ݨӨ���k�l�]���۷��\�O�A���O�A
ı�o�o�Ӧa����L�a��n�����@�Ӧa�褣��l�A�A�]�����W������a��
���P�A�@�Ѥ�򪺷Pı�q�A�ߩ��B�ɰ_�C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "���s" : "�@�ӧ@�Τ������˸m(push button)?\n"
]));

        set("exits", ([ /*�����I[�{]file_name room18*/
  "south" : __DIR__"room18", 
  "north"  : __DIR__"room27",
//  "northwest"  : __DIR__"room20",
//  "southeast"  : __DIR__"room21",
//  "southwest"  : __DIR__"room22",
//  "up"  : __DIR__"room23",
//  "down"  : __DIR__"room24",
//  "north"  : __DIR__"room25",
]));
set("light",1);
        set("objects", ([
 __DIR__"npc/win" : 1,
]));
        set("no_recall",1);
        setup();
}
void init()
{
      add_action("do_push","push");
}

int do_push(string arg)
{
       object me;
       me=this_player();
	if( arg != "button")
       return 0;
       else {
message_vision(HIG"$N����b�F�䪺�@�ӫ��s�W�@���A$N�ߨ�Q�@�ѱj���l�J����̡I\n"NOR,me);
       me->move(__DIR__"room26"); 
message_vision(HIY"$N�������b�@�}�j�����v���M���X�ӡC\n"NOR,me);
          return 1;
        }
}


