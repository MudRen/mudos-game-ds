// Room: /u/t/tmr/area/waroom.c

inherit ROOM;

void create()
{
	set("short", "��ߤp��");
	set("long", @LONG
�@���Φˤl�s´�Ӧ��p�ΡA�Ъ٤p�����n�A�ᬰ�붮�C�p�ٰ��B�W�g
�ۡu�H�y�v�G�r�A���P�����t�s�C�Τ����F�X�i���i�B�˴ȡA�èS������
�S���B�C�Υ~�u���@�i��l�A�A��弭��ӨӪ��p��o�w�����h�V�A�ݼ�
�l�A�n���}�o�̡A�]�u����a�^�h�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wa1",
]));
	set("light",1);
set("item_desc",([
"���B":"�@����w�}�ª����B�A�����O�_��ı�A�Aı�o���B���Y�o�X�Ƕ�����~�I�H\n",
]) );

	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_search","search");
}

int i= 1;

int do_search(string arg)
{
        object me,fist;
          fist=new(__DIR__"npc/wp/sun-snow-fist");      
        if( !arg || arg!="���B" ) return 0;
      me=this_player();
         if( me->query("level") > 14 && i==1 )
        {
        message_vision("$N�j�F�j�W�Y�����B�A���M���F�@������⪺���ơC\n",me);
          fist->move(environment(me) );
        i=0;
        }
        else
        {
        message_vision("$N�j�F�j�W�Y�����B�A���G����]�S���o�{�C\n",me);
        }               
        return 1;
}
