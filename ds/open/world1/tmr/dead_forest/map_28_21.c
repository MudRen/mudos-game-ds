inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG
�Aı�o�o�઺�Ů�D�`���D�A���Ѵc�������D�C
LONG
);
	set("exits",([
		"south" : __DIR__"map_29_21",
		"north" : __DIR__"map_27_21",
	]));
        setup();
        set("map_long",1);     //show map as long
        //replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg) 
{
  	object me;
   	mapping cnd_data=([]);
   	me = this_player();
	// ���h�r
    cnd_data["damage"] = 40;
	cnd_data["duration"] = 3; // �N�o�@3��
	cnd_data["��"] = 10 ; // gin
	me->set_condition("marsh-poison", cnd_data);
	message_vision("$N�|�B½½���A���o�S������i�ä��B�A��ı�o���馳�I���ΪA�C\n" , me);
	return 1;
}