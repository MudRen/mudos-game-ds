#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ѫ�");
        set("long", @long
�o�̬O�ڤ��P�����ѭ̩w���|��}�|���|ĳ�ǡA�A�i�H�ݨ�ж�
�������\�F�@�i���C�b�o��Q�ׯ��ڪ��Ҧ��j�j�p�p���Mĳ�ƶ��A
�W�����W�שw�A�U�ܱڤH�H���g�@�C

long);
        set("exits", ([
  "south" : __DIR__"ladd-2",
]));
        set("objects", ([ 
  __DIR__"item/god_box.c" : 1,
]));
        set("light", 1);
        setup();
        set("stroom", 1);
        call_other("/obj/board/club_god_2.c", "???");
}
void init()
{
     if( CLUB_D->check_member("god",getuid(this_player())) < 3 && !wizardp(this_player()))
        {
                this_player()->move(__DIR__"ladd-2");
                message_vision(HIY" �ѯ���$N��: �o�̤��O�A�ӨӪ��a���C\n"NOR, this_player());
        }
}

