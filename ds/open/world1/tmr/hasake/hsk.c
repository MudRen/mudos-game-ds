// hsk.c ���ħJ�b�O
inherit ROOM;
void create()
{
        set("short", "���ħJ�b�O");
        set("long", @LONG
�o�O���ħJ�ڤH�~���b�O�A����T�V�A�����H�@�ʤ찵�D��A�|
�P�Τp��γ򦨤@��A�q�D��Ԥ��ֱb�O�L��ΦA�v��a�W�C���W�~��
�����ڳ����w�o�رb�O�A��K²��C�]�X�j�ڤH�Ƴ̦h�A�ҥH�S�κٳo��
�b�O�����X�j�]���C
LONG);
        set("exits", ([
            "west" : __DIR__"caoyuan8",
         ]));
         set("objects", ([
              __DIR__"npc/hasake1" : 1,
             __DIR__"obj/cheese" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}
