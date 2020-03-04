// Room: /future/area/digging_road10.c

inherit ROOM;

void create()
{
        set("short", "�q�}��");
        set("long", @LONG
�A���b�@�B�q�}�̡A�q�}�F��e�����B���Q���ءA�}���W�C�j������
�N�]�@�u�֢������X�o���O�v�A�ӱo�q�}�̥իG�p�ޡA�|�P�򰣤F���q��
�q�u���~�A�٦��X�x���U���q�@�~���b�H���B�q���C�A���g�N�a�ݨ�}��
���q�����G�o�X�Ǫ�������~�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "northeast" : __DIR__"digging_road7",
        ]));

        set("world", "future");
        set("light",1);
        set("item_desc",([
        "H2O���X�o���O":
"H2O���X�o���O���G�Q�@�����ҵo���X�Ӫ��A�o����z�����X\n"
"��(H2O)�����B�B��ӵo���A��һݯ෽�N�u�ݲM���C\n",
        "�b�H���B�q��":
"�b�H���B�q�����B�q�������A���Y���G�����q�ξ������u�A��\n"
"���@�p���bAI���q�l���A���¥@�ɱ��q�ɼ��������U�����H�A�{���w\n"
"�֦��H�ΡC\n",
               "�q��":
"�@�طs�o�{����ơA�{�ɤH�̳����Ӵ��M�ĥΡA���{�b���ӤH\n"
"�b�j�q���ʳo���q�ۡA�ݨӱN����(excavate)�X�ӽ汼�|���i�[�����J�C\n",
        ]) );
        set("mineral",50); //�q�ۼƶq
        set("no_clean_up", 0);

        setup();
}
void init()
{
               add_action("do_excavate","excavate");
}
int do_excavate(string arg)
{

        object me,ob;
        me = this_player();

        if(!arg || arg!="�q��")
                return notify_fail("�A�n������O?\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�S�Ŷi����q�u�@�C\n");
        if(me->query("hp") < 10)
                return notify_fail("�A�����骬�p���n�A�L�k�i����q�u�@�C\n");
	if(!objectp(present("iron shovel",me) ) ) 
        	return notify_fail("�A�o�������g���u��C\n");

        
        message_vision("$N�Q�Τ⤤���K��F���@�g�B����@�|���}�l��M�q��....\n",me);
        me->receive_damage("hp",5);
        me->start_busy(3);

        if( query("mineral") < 1 || random(80) < 30 )
		return notify_fail("�A���F���B�Y�W�����A���G�S����o�{�C\n");

	if(random(30)==1) {
	        message_vision("$N���G����F�@�������⪺�q���C\n",me);
	        ob = new(__DIR__"obj/mineral2.c");
	        ob->move(me);
	        add("mineral",-2 );

	}
	else	{
	        message_vision("$N���G����F�@���t���⪺�q���C\n",me);
	        ob = new(__DIR__"obj/mineral1.c");
	        ob->move(me);
	        add("mineral",-1 );
	}

        return 1;
}
