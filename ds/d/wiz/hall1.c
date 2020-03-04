// Room: /d/wiz/hall1.c

inherit ROOM;

void create()
{
 set("short", "�Ův����U");
 set("long", @LONG

  �o�̬O�Ův��ѰQ�ת��a��A�p�G�Ův�̭n�}�|���ܡA�]�h�b�|��b�o
���|��C���F�O�Ův�|�ȫǡA�O�Ův���ݪ��a���a��C�_��O�Ův�̳��i
�u�@�p���P�u�@�i�ת�²���ǡC�q�ӱ詹�W���i�H��U�������Ův�Q�װ�
�A�̳��Ӫ��K�ǬODS���p�|ĳ�U�A���T�۷��Y��C�o���٦��T�ӳy���۲�
�����A�i�H���O�q��T�j�ɥN���u�@�Q���U�C�o�̦��ӧG�i��A�i�K����
�O�Ův�̥������D�����n�q���P���i�A�@�w�n�ݧ��~�i�H���}��C

LONG
        );
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "future" : "/open/world3/meetroom",
    "past"   : "/open/world1/meetroom",
    "now"    : "/open/world2/meetroom",
    "north"  : __DIR__"jobroom",
    "up"     : __DIR__"hall_area",
    "east"   : __DIR__"entrance",
//    "west"   : __DIR__"testroom",
    "down"   : __DIR__"meetroom",
  "game" : "/open/world1/wilfred/club/dragon/online",
 ]));
  set("objects",([
// __DIR__"npc/npc_wiz":1,
// "/obj/box":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/wizard_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("�D���a���⤣��i�J�}��ϰ�C\n");
        return ::valid_leave(me, dir);
}

