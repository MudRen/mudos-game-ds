// 可影印的雜誌
inherit ITEM;

void create()
{
	set_name("愛神丘比特創刊號",({"love magazine","magazine","love"}) );
	set("long",@LONG

  ◢█◣◢█◣  ◢█◣◢█◣  ◢█◣◢█◣  ◢█◣◢█◣  ◢█◣◢█◣
  ██████  ██████  ██████  ██████  ██████
  ◥████◤  ◥████◤  ◥████◤  ◥████◤  ◥████◤
    ◥██◤      ◥██◤      ◥██◤      ◥██◤      ◥██◤  
      ◥◤          ◥◤          ◥◤          ◥◤          ◥◤    

	紅色的玫瑰花 藍色的紫羅蘭 讓我們掉進愛情的漩渦理1天或2天
	把這封信送給8個人以上，你心愛的人會來約你!
	送給12個人以上，你心愛的人會吻你!
	送給16個人以上，你心愛會愛上你!
	送給100個人以上，你心愛的人會會變你女(男)朋友
LONG
	);
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",220);
		set("unit","本");
	}

	setup();
}

int can_copy()
{
	return 1;
}

int is_magzine()
{
	return 1;
}

