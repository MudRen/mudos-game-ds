inherit ROOM;
void create()
{
  set ("short", "�å۱^");
  set ("long", @LONG
�A�b�F�z���è��A���G���M�o�{�e�褣���B���y�p�s�A�n�_���X
�ϧA�e���@���s���C
LONG
);

  set("exits", ([
  "west" : __DIR__"room29",
  "eastup" : __DIR__"room31",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
