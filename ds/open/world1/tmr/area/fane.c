inherit ROOM;

void create()
{
        set("short", "�s���q");
        set("long", @LONG
�o�O�@�����s���������@���p�q�A�j���W���۶��Z�������A�q�̨�
�^�ۤT�L�������~�A���\�m�ۤ@�i����Τ@�����l�A�u����W�񺡤F�A��
�B���G�����������~�A�l�������Ҵ��X���ϧ�O��¶�����C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"vroad3",
        ]));
        set("objects",([
    __DIR__"npc/old-man":1, 
    //__DIR__"npc/thief_master":1,
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
