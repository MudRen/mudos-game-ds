// Room: /open/world1/acme/area/senwu4.c

inherit ROOM;

// �۵M�_�[-�Ѧ��r��
// add by tmr 2006/11/15
void open_skypool2() {
        "/adm/daemons/event/skypool.c"->trigger_event();
}

void open_skypool() {
        call_out("open_skypool2",60+random(30));
}

void create()
{
	set("short", "���x");
	set("long", @LONG
�b�o���x�W�A��ۤ@�i�j�ۮ�A�b�Ǥ]���@�i�۴ȡA�b�ۮ�W�Y
��m���ۤT�K�������l�A���o�X�O�H���M��n���͸��ȭ��A�b�ۮ�W
�t���\�h�k���A��������@�ΡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"senwu3",
]));
set("objects",([
    __DIR__"npc/advmaster.c" : 1,
]) );
	set("world", "past");
    set("outdoors","land");
	set("no_clean_up", 0);

        set("valid_startroom", 1);
	setup();
}
