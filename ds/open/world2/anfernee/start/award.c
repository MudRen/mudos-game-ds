#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ův���������");
        set("long", @LONG
�o�̬O�u���Ův�~�i�i�J����������ϡA�b�Ův�ѨM���Τ���A�N�i
�즹���i�ҭn award  ����H���I�ơA�нѦ�Ův�b���ध��е����w��
��A���¡C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
 "south" : __DIR__"bug",
]) );
        set("light",1);
        set("no_clean_up", 0);
        setup();
        call_other( "/obj/board/award_b", "???" );
}

void init()
{
 if( !wizardp(this_player()) )
 {
  write(HIR" �o�̤��O���a�i�i�J���a�� !!! ���Ȩt�Φ۰ʰh�X���a !!! "NOR);
  this_player()->move(__DIR__"bug");
 }
}
