// sroom.c �Ω�
inherit ROOM;

void create()
{
        set("short", "���ħJ�b�O");
        set("long", @LONG
�o�O���ħJ�ڤH�~���b�O�A�b�O���Φϥ־Q�a�A�|�P�]���F�n�Ǧ�
�֤��֡A����O�@�i�ηF��ԩ����Ϥ�ɡA�J�f���@�p���֡C�ݰ_�ӥD�H
���G���b�a�A�A�p�G�֤F�N�����@�U�a�C
LONG);
        set("exits", ([            
            "southeast" : __DIR__"shop",            
        ]));                
        setup();
        replace_program(ROOM);
}
