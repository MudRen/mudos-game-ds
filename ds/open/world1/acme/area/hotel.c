inherit ROOM;

void create()
{
        set("short", "�ѭ��ȴ�");
        set("light",1);
        set("long", @LONG
�o�̬O�@���ȴ̡A���f���۰��j���۵P�A�W�g�ۡy�ѭ��ȴ̡z�A�u
�����p�G����Ԫ��۩I�ȤH�A�b�F�䦳�ӤW�Ӫ��ӱ�A����g�F�u�G��
���y�v�A���G�O���@�ǹF�x�Q�H�ϥΪ��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hotel2f",
  "north" : __DIR__"st.c",
]));
      set("objects", ([
         __DIR__"npc/oldwang" : 1,
// �S�n�S���J..:P         __DIR__"npc/drooler" : 1,
           __DIR__"npc/fanny" : 1,
       ]));
           set("room_type","hotel");       //���]
        set("no_fight", 1);
        set("no_clean_up", 0);

        set("valid_startroom", 1);
        setup();
     call_other("/obj/board/acme_h1_b", "???");
}
