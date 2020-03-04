  // Room: /u/t/tmr/room/square.c

  inherit ROOM;

  void create()
  {
          set("short", "���ռs��");
          set("long", @LONG
  �o�O�@�ө_(Tmr)�ΨӰ����ժ��s���C
LONG
          );
          set("exits", ([ /* sizeof() == 3 */
            "out" : "/u/t/tmr/workroom",
          ]));
          set("no_clean_up", 0);
          setup();
  }

  void init()
  {
          add_action("do_test","test");
  }

  int do_test(string arg)
  {
            object room,env,me;
          mapping exit;

	me=this_player();
          if(!arg ) return notify_fail("�п�ܧA�n���ժ���V�C\n");


          env = environment(me);
          if(!env) return notify_fail("�A���̤]�h���F�C\n");
          exit = env->query("exits");

          if(!mapp(exit))
                  return notify_fail("�o�өж��S���i�Ѵ��ժ��X�f�C\n");

          if( undefinedp(exit[arg]) )
                  return notify_fail("�S���o�Ӥ�V�i�Ѵ��աC\n");
          if( !(room = find_object(exit[arg])) ) call_other(exit[arg], "???");
          if( !(room = find_object(exit[arg])) ) 
                  return notify_fail("�L�k���ʡC\n");

	tell_object(me,"\n"+exit[arg]+"���u�ԭz(short)�G\n\n"+
                  room->query("short")+"\n" );

          return 1;       
  }

