inherit ROOM;
void create()
{
	object b;
	
        set("short", "�p�ӫ�");
        set("long",@LONG
�o���ӫǸ̰ﺡ�F���A�X�G�N�Ƥ��~���F��C�a�W���n�X�ӽc�l
�A���F�b�̨������O�K�c�l���~�A��L���O��c�l�C�Ӥ�c�l�̭���
�O�ѥ��A�q�Ѥl�ʮa�B�L�k�Ѩ�����ǡA�k�M�O�@�Ӥp���Ϯ��]�C��
�L�A�����D������A�o�Ǯѳ��S������A�s�o�`���S���A�u�O�O�H��
�_�C
LONG
        );
        set("exits", ([
        "west" : __DIR__"grav4.c",
        ]));
        
        set("objects",([
	__DIR__"obj/iron_box.c":1,
	]));
	/*if(this_object()->query_temp("opened")!=1)
	{
		b=new(__DIR__"obj/iron_box.c");
		b->move(this_object());
	}*/
	
        set("item_desc",([
        "��c�l" : "�̭����ۤ��֪����y�C\n",
        ]));
        set("light", 0);
        setup();
	replace_program(ROOM);
}