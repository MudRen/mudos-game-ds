  inherit ITEM;
  void create()
  {
          set_name("�H",({ "letter" }));
          set_weight(800);

          if( clonep() )
                  set_default_object(__FILE__);
          else
          {
                  set("long","�@�ʯ}�}���ꪺ�H..\n");
                  set("unit","��");
                  set("value",40);
          }
          setup();
  }

