inherit ROOM;
void create()
{
  set ("short", "�k�Y�s��");
  set ("long", @LONG
�򥪽Y�s���ۤ�A�o�̥k�Y�s�����槽�K��o�U�p�A�Τ������Q
�ب���A�b���������Ӥj���l�A���l�~�Y�Q�a�H�����⯻�A�b���ճ�
�����ۨⰦ���s�A�l�����K�ءA�ݨӬO�N�h���m���ΩСC
LONG
);
  set("exits", ([
  "west" : __DIR__"room90",
]));
  set("objects",([
  __DIR__"npc/obj/obj29" : 1,
]));

  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
