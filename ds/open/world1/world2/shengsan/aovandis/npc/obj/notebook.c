// ���O���q��
inherit ITEM;

void create()
{
    set_name("�^��½Ķ��",({"english translator","translator"}) );
  set("long",@LONG
�@���p�p���x�W�����^��½Ķ���C
LONG
);
	set_weight(15000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
set("value",3000);
		set("unit","�x");   //luky
set("material", "iron");
	}
	setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1) 
 {
      tell_object(me,"�o�x�q���w�g�S�q�F!\n");	
      return 1;
 }
 if(arg!="computer") return 0;
 
 tell_object(me,"���O�q���o�X�@�n�G�s: �f�c��f����f�C���\n�n����F�A�ۤv�O���a�C\n");
 return 1;
}
