inherit ROOM;

void create()
{
        set("short", "�ȴ̤G��");
         set("light",1);
        set("long", @LONG
�o�̬O�ѭ��ȴ̪��G�Ӷ��y�A�u���o�̰s��R�ѡA�@�Ǧ��I���઺
�H�b�o�[�ܵۦE�s���A�����٦��X�쳭�s���h�Q�A���u���y�v��M�u�O
�ӷE�l�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hotel",
]));
        set("no_clean_up", 0);

        set("objects",([
           __DIR__"npc/chun" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
