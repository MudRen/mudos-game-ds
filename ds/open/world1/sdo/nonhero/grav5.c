inherit ROOM;
void create()
{
	
        set("short", "�p�ӫ�");
        set("long",@LONG
�S�Q��o���٦��@�өж��C��~�����P���O�A�o�̪��|�P����W
���۳\�h���Z���C�A�J�Ӫ��ˬd�F�o�̡A�o�{�F�@�ӽc�l�C���L�A��
��ı�i�D�A�G�y�o�ӽc�l���M�I�I�z
LONG
        );
        set("exits", ([
        "east" : __DIR__"grav4.c",
        ]));
        
        set("objects",([
	__DIR__"obj/gold_box.c":1,
	]));
	/*if(this_object()->query_temp("opened")!=1)
	{
		b=new(__DIR__"obj/gold_box.c");
		b->move(this_object());
	}*/

        set("item_desc",([
        "�Z��" : "��W���ۦU���U�˪��Z���A���L�����ä���ϥΤF�C\n",
        ]));
        set("light", 0);
        setup();
        replace_program(ROOM);
}
