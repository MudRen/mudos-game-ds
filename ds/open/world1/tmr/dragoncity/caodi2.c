// Room: /open/world1/tmr/dragoncity/caodi2.c

inherit MOBROOM;

void create()
{
	set("short", "���S���J-��a");
	set("long", @LONG
�o��O���S���J�s���~���j��a�A���_�i�H�樣�֫ӭx
�P��H�K��ڲצ~���Ԫ��D�n�Ԧa�ж��S���J�s���A���M�o
��S���b�I�Ԥ��A���|�g��^�o�O�R�����ݵ±�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi4",
  "west" : __DIR__"caodi1",
]));
	set("current_light", 6);
	set("no_clean_up", 0);
	set("outdoors", "land");
        set("chance", 60); 
        set("mob_amount",3);     
           set("mob_object",({  
                  __DIR__"npc/tiger1",
                   __DIR__"npc/tiger2",
                   __DIR__"npc/tiger3",
        }));


	setup();
}
