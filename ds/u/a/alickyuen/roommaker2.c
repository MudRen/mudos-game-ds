#define RMK_VERSION " (v3.2 �ץ���) "
inherit ITEM;

string *special_props = ({
        "short", "long" });
int save_room_file(string yn, string file, string str);
int do_mkroom (string file);
int get_short (string rep, string arg);
int get_long (string rep, string arg);
int get_file_name (string rep);
int get_no_fight (string rep);
int get_no_magic (string ep);
int get_no_clean_up (string rep);
int get_valid_startroom (string rep);
int confirm_outdoors (string rep, string arg);
int get_item_desc_name (string rep);
int get_item_desc (string rep, string arg);
int get_exits (string rep);
int get_exit (string rep, string arg);
int get_objects (string rep);
int save_file();
int init_var();

mapping tmp = ([
  "no_fight"            :       0,
  "no_magic"            :       0,
  "no_clean_up"         :       0,
  "valid_startroom"     :       0,
  "file_name"           :       "",
  "short"               :       "",
  "long"                :       "",
  "outdoors"            :       "",
  "item_desc"           :       ([]),
  "exits"               :       ([]),
  "objects"             :       ([]),
]);

string *special_props = ({
        "short", "long", "file_name" });

int create()
{
        set_name("�ж��s�边" + RMK_VERSION, ({ "roommaker", "maker" }) );
        set_weight(1);
        set("value",0);
        set("unit", "��" );
        set("long", @LONG
�o�O�@�ӥΨӡu�ֳt�v�s�y�ж����u��M���U�ɶ����h�Φ��Y��  lag ���Ův
�Q�νu�W��J�s�y²�檺�ж��M���L�p�G�A�Q�����ۤv�ϰ�ж����~��M�̦n
���n�Ө̿�o�ӪF��, ��A��y�ж���, �|���@����D, �p�G�A�Q�ιw�]��,
�Ъ����� enter, �p�G�Q���, �ХΥy�I�����C

mkroom <��V> <�ж��ɦW>        �y�X�@�ӡu�šv�ж�
rset <�ж��ݩ�> <�ݩʤ��e>      �]�w�A�ثe�Ҧb�ж����ݩ�
uset <�ж��ݩ�>                 �����ثe�Ҧb�ж����Y���ݩ�
connect <��V> <�ж��ɦW>       �N�A�ثe�Ҧb���ж��s���@�ӥX�f��t�@�өж��C
dconnect <��V>                 �����@�ӥX�f
addobj <�����ɦW> <�Ӽ�>        �b�өж��W�[����
delobj <�����ɦW>               �����өж�������
saveroom                        �N�A�ثe�Ҧb���ж��s�ɡC

�`�N: �i�H�� help roommaker ���o�ԲӸѻ�
LONG
        );
        setup();
}

int init()
{
        if( wizardp(environment()) ) {
                seteuid(getuid(environment()));
                add_action("do_mkroom", "mkroom");
                add_action("do_rset", "rset");
                add_action("do_uset", "uset");
                add_action("do_setlong", "setlong");
                add_action("do_connect", "connect");
                add_action("do_dconnect", "dconnect");
                add_action ("do_addobj", "addobj");
                add_action ("do_delobj", "delobj");
                add_action("do_saveroom", "saveroom");
        }
}

string ob_path(mixed ob)
{
        string file;
        string *dir;
        int     i;

        if (objectp(ob))
          file = base_name(ob);
        else if (stringp(ob)) file = ob;
        else return "/";
        dir = explode(file, "/");
        file = "/";
        for (i=0; i<sizeof(dir)-1; i++)
          file += dir[i]+"/";
        return file;
}

string get_cwd()
{
  object        env;
  string        file;
  int           i;

  env = environment(this_player());
  file = file_name(env) + ".c";
  i = strlen(file)-1;
  while( (i > 0) && (file[i]!='/')) i--;
  if (i>0) return file[0..i];
  else return "/";
}

int do_delobj (string arg)
{
        mapping objects;
        object  ob;
        string file, cwd;
        int     num;

        if( !arg || sscanf(arg, "%s", file)!=1 )
                return notify_fail("���O�榡�Rdelobj <�����ɦW>\n"
                                   "      �p: delobj /open/su/obj/cloth\n");
        objects = environment(this_player())->query("objects");
        if (ob=present (file, environment(this_player()))) {
          file = resolve_path(this_player()->query("cwd"), file);
          if( mapp(objects) )
                map_delete (objects, file);
          destruct (ob);
          write("Ok.\n");
          return 1;
        }
        else
          return notify_fail ("�t�Χi�D�A, �S�o�˪F�F: "+file+"\n");
}

int do_addobj (string arg)
{
  mapping objects;
  string file;
  object ob, me;
  int   num;

  if( !arg || sscanf(arg, "%s %d", file, num)!=2 )
    return notify_fail("���O�榡�Raddobj <�����ɦW> <����Ӽ�>\n");
  me = this_player();
  file = resolve_path(me->query("cwd"), file);
  ob = new (file);
  if (!ob) return notify_fail ("�t�Χi�D�A: �S���Ӫ���: "+file+"�C\n");
  ob->move(environment (me));
  objects  = environment(me)->query("objects");
log_file( "static/addobj", sprintf("%s --> %s (%s)\n",me->query("id"),
ob->query("name"), ob->query("id")));
  if( mapp(objects) )
    objects[file] = num;
  else
    environment(me)->set("objects", ([ file:num ]) );
  write("Ok.\n");

  return 1;
}

void done_setlong (object me, string text)
{
        environment(me)->set("long", text);
        return ;
}

int do_setlong ()
{
  this_player()->edit( (: done_setlong, this_player() :) );
  return 1;
}

int do_uset(string arg)
{
        string prop, str;

        if( !arg || sscanf(arg, "%s", prop)!=1 )
                return notify_fail("���O�榡�Ruset <�ж��ݩ�>\n"
                                   "      �p: uset light\n");

        environment(this_player())->delete(prop);
        write("Ok.\n");
        return 1;
}

int do_rset(string arg)
{
        string prop,str;
        int data, i, n;

        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
                return notify_fail("���O�榡�Rrset <�ж��ݩ�> <�ݩʤ��e>\n");

        n = strlen (str);
        if (str[0] == '"' && str[n-1] == '"') {
          write ("set "+prop+" = \""+str[1..n-2]+"\"\n");
          environment(this_player())->set(prop, str[1..n-2]);
          return 1;
        }

        data = 0;
        for (i=0; i<n; i++)
          if (str[i] < '0' || str[i] > '9') {
            data = 1;
            break;
          }

        if( !data && sscanf(str, "%d", data)==1 ) {
          write ("set "+prop+" = "+data+"\n");
          environment(this_player())->add(prop, data);
        }
        else {
          write ("set "+prop+" = \""+str+"\"\n");
          environment(this_player())->set(prop, str);
        }
        return 1;
}

int do_dconnect(string arg)
{
        mapping exits;
        string dir;

        if( !arg || sscanf(arg, "%s", dir)!=1 )
                return notify_fail("���O�榡�Rdconnect <��V>\n"
                                   "      �p: dconnect east\n");
        exits = environment(this_player())->query("exits");
        if( mapp(exits) )
                map_delete (exits, dir);
        write("Ok.\n");
        return 1;
}

int do_connect(string arg)
{
        object  from;
        mapping exits;
        string dir, file;

        from = environment(this_player());
        if( !arg || sscanf(arg, "%s %s", dir, file)!=2 )
                return notify_fail("���O�榡�Rconnect <��V> <�ж��ɦW>\n");
        file = resolve_path(ob_path(from), file);
        exits = from->query("exits");
        if( mapp(exits) )
                exits[dir] = file;
        else
                from->set("exits", ([ dir: file ]) );
         write("Ok.\n");
        return 1;
}

int save_room_file(string yn, string file, string str)
{
  string        tmp;
  int           i;

  if( strlen(yn)<1 || yn[0]!='y' ) return 1;

  i = sizeof(file)-1;
  if (!(file[i] == 'c' && file[i-1] == '.')) file = file+".c";
  write ("file name is " + file + "\n");
  if ( write_file(file, str, 1) ) {
    write("Ok.\n");
    return 1;
  }
  else {
    write ("roommaker ���ռg�J("+file+")����!!\n");
    return 0;
  }
}

void owner_is_killed() { destruct(this_object()); }

int do_mkroom(string arg)
{
  string        here, dir;
  int           status=0;

  if (!arg) return
    notify_fail ("mkroom [<��V> <�ж����ɦW>] �� mkroom <�ж����ɦW>\n");
  init_var();
  here  = file_name (environment(this_player()));
  if (sscanf (arg, "%s %s", dir, arg) == 2) {
    arg = resolve_path(get_cwd(), arg);
    do_connect (dir+" "+arg);
  }
  else
   arg = resolve_path(this_player()->query("cwd"), arg);

  if (arg == here) {
    write ("�п�J�ɦW, �ФũR�W�� "+here+" : ");
    input_to ( "get_file_name" );
  }
  else {
    tmp["file_name"] = arg;
    write ("file name is "+arg+"\n");
    write ("�п�J no_fight ���� (0 �w�]���i�԰�) : ");
    input_to ( "get_no_fight" );
  }
  return 1;
}

int get_file_name (string rep)
{
  string        dir, *path;

  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep=="") {
    write ("���i�H�S���ɦW, �ЦA��J�@��, ���s��Ы��y�I . ����\n");
    input_to ( "get_file_name" );
    return 1;
  }
  else {
    dir = file_name (environment(this_player()));
    path = explode (dir, "/");
    path[sizeof(path)-1] = "/"+rep;
    tmp["file_name"] = "/"+implode (path, "/");
    write ("file name is "+rep+"\n");
  }

  write ("�п�J no_fight ���� (0 �w�]���i�԰�) : ");
  input_to ( "get_no_fight" );
  return 1;
}

int get_no_fight (string rep)
{
  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep == "") tmp["no_fight"] = 0;
  else if (sscanf (rep, "%d", tmp["no_fight"]) != 1) {
    write ("�A����J���O�Ʀr, ���ӬO 0 �� 1\n");
    write ("�п�J no_fight ���� (0 �w�]���i�԰�) : ");
    input_to ( "get_no_fight" );
    return 1;
  }

  write ("�п�J no_magic ���� (0 �w�]���i�I�]�k) : ");
  input_to ( "get_no_magic" );

  return 1;
}

int get_no_magic (string rep)
{
  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep == "") tmp["no_magic"] = 0;
  else if (sscanf (rep, "%d", tmp["no_magic"]) != 1) {
    write ("�A����J���O�Ʀr, ���ӬO 0 �� 1\n");
    write ("�п�J no_magic ���� (0 �w�]���i�I�]�k) : ");
    input_to ( "get_no_magic" );
    return 1;
  }

  write ("�п�J no_clean_up ���� (0 �w�]���n reborn) : ");
  input_to ( "get_no_clean_up" );
  return 1;
}

int get_no_clean_up (string rep)
{
  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep == "") tmp["no_clean_up"] = 0;
  else if (sscanf (rep, "%d", tmp["no_clean_up"]) != 1) {
    write ("�A����J���O�Ʀr, ���ӬO 0 �� 1\n");
    write ("�п�J no_clean_up ���� (0 �w�]���i�I�]�k) : ");
    input_to ( "get_no_clean_up" );
    return 1;
  }

  write ("�п�J valid_startroom ���� (0 �w�]�����ж����i��_�I) : ");
  input_to ( "get_valid_startroom" );
  return 1;
}

int get_valid_startroom (string rep)
{
  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep == "") tmp["valid_startroom"] = 0;
  else if (sscanf (rep, "%d", tmp["no_clean_up"]) != 1) {
    write ("�A����J���O�Ʀr, ���ӬO 0 �� 1\n");
    write ("�п�J valid_startroom ���� (0 �w�]�����ж����i��_�I) : ");
    input_to ( "get_valid_startroom" );
    return 1;
  }

  write ("�п�J�ж��W�� short (�ũж�) : ");
  input_to ( "get_short", "�ũж�" );
  return 1;
}

int get_short (string rep, string arg)
{
  string long="�o�O�@�����򳣨S�����ж��C\n";

  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep=="") tmp["short"] = arg;
  else tmp["short"] = rep;

  write ("�п�J long ���� (" + long + ") : \n");
  this_player()->edit( (: get_long, long :) );

  return 1;
}

int get_long (string arg, string rep)
{
  if (rep=="") tmp["long"] = arg;
 else tmp["long"] = rep;

  write ("�O��~��? (y) : ");
  input_to ( "confirm_outdoors", "y" );
  return 1;
}

int confirm_outdoors (string rep, string arg)
{
  string d;

  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep == "n") {
        write ("�п�J���[ item_desc ���W��, �p�G�Q�������[, �Ъ����� enter : ")
;
        input_to ( "get_item_desc_name" );
        return 1;
 }
  else if ( arg == "y" && (rep == "" || rep[0] == 'y' || rep[0] == 'Y') ) {
    d = "/"+implode( explode(this_player()->query("cwd"), "/")[0..1], "/");
    write ("��~�O�ݩ���@�ӥؿ�? ("+d+") : ");
    input_to ( "confirm_outdoors", d );
    return 1;
 }
  else if (rep=="") tmp["outdoors"] = arg;
  else tmp["outdoors"] = rep;

  write ("�п�J���[ item_desc ���W��, �p�G�Q�������[, �Ъ����� enter : ");
  input_to ( "get_item_desc_name" );
  return 1;
}

int get_item_desc_name (string rep)
{
  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep=="") {
    write ("�г]�w�X�f exits ���s����V, �Q�����]�w, �Ъ����� enter : ");
    input_to ( "get_exits" );
    return 1;
  }

  write ("�п�J "+rep+" �����[���e, �Q�����ɽЪ����� . ���}�s��\n");
  tmp["item_desc"][rep] = "";
  this_player()->edit ( (: get_item_desc, rep :) );
  return 1;
}

int get_item_desc (string arg, string rep)
{
  if (rep != "") {
    tmp["item_desc"][arg] = rep;
    write ("�п�J�U�@���[ item_desc ���W��, �Q�������[, �Ъ����� enter : ");
    input_to ( "get_item_desc_name" );
    return 1;
  }

  write ("�г]�w�X�f exits ���s����V, �Q�����]�w, �Ъ����� enter : ");
  input_to ( "get_exits" );
  return 1;
}

int get_exits (string rep)
{
  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep=="") {
    if (tmp["exits"][""]) map_delete(tmp["exits"], "");
    write ("�г]�w���� objects ���ɦW, �Q�����]�w, �Ъ����� enter :\n");
    input_to ( "get_objects" );
    return 1;
 }
  else {
    write ("�п�J "+rep+" ���s���ж��ɦW, �i�H�ĥά۹���|�k : ");
    tmp["exits"][rep] = "";
    input_to ( "get_exit", rep );
  }
  return 1;
}

int get_exit (string rep, string arg)
{
  if (rep != "") {
    tmp["exits"][arg] = resolve_path(this_player()->query("cwd"), rep);
    write ("�г]�w�X�f exits ����V, �Q�����]�w, �Ъ����� enter : ");
    input_to ( "get_exits" );
    return 1;
  }

  write ("�г]�w���� objects ���ɦW, �Q�����]�w, �Ъ����� enter : ");
  input_to ( "get_objects" );
  return 1;
}
int get_objects (string rep)
{
  object        ob;

  if (rep == ".") { write ("�A��󥻦��s��C\n"); return 1; }
  else if (rep=="") {
    save_file ();
    return 1;
  }

  rep=resolve_path(this_player()->query("cwd"), rep);
  ob = new (rep);
  if (!ob) {
    write ("�t�Χi�D�A: �S���Ӫ���: "+rep+"�C\n");
    write ("�г]�w���� objects ���ɦW, �Q�����]�w, �Ъ����� enter : ");
    input_to ( "get_objects" );
    return 1;
  }

  destruct (ob);

  write ("�п�J "+rep+" ������Ӽ� : ");
  tmp["objects"][rep] = 1;
  input_to ( "get_object", rep );
  return 1;
}

int get_object (string rep, string arg)
{
  int           n;

  if (rep != "") {
    if (sscanf(rep, "%d", n) != 1) {
      write ("�A�骺�Ȥ��X�k, �Э��s��J "+arg+" ������Ӽ� : ");
      input_to ( "get_object", arg );
      return 1;
    }
    else {
      tmp["objects"][arg] = n;
      write ("�г]�w���� objects ���ɦW, �Q�����]�w, �Ъ����� enter : ");
      input_to ( "get_objects" );
      return 1;
    }
  }

  tmp["objects"][arg] = 1;
  save_file();
  return 1;
}

int save_file()
{
  string        room_code, *name, file;
  int           i, n;

  // room_code �O�ж����{���X, ���U�o�@�q�O�Ҧ��ж����@�q�I
  room_code = "// Room: " + tmp["file_name"] + @ROOM_CODE

inherit ROOM;

void create()
{
ROOM_CODE;
  // �@����o�䵲��

  room_code =
    sprintf ("%s  set (\"short\", \"%s\");\n"
               "  set (\"long\", @LONG\n%sLONG);\n\n",
             room_code, tmp["short"], tmp["long"]);

  name = keys(tmp);
  for(i=0; i<sizeof(name); i++) {
    if( member_array(name[i], special_props)!=-1 ) continue;
      if ( (intp(tmp[name[i]]) && tmp[name[i]]>0) ||
        (stringp(tmp[name[i]]) && tmp[name[i]] != "") ||
                (mapp(tmp[name[i]]) && tmp[name[i]] == ([])) ||
                sizeof (tmp[name[i]]) > 0)
                    room_code += sprintf("  set(\"%s\", %O);\n",
                                   name[i], tmp[name[i]] );
  }

  room_code += "  setup();\n  replace_program(ROOM);\n}\n";

  // Replace current directory with __DIR__ macro to make relocatable code.
  file = tmp["file_name"];
  i = strlen(file)-1;
  if (!file[i] == 'c' || !file[i-1] == '.') file += ".c";
  while( (i > 0) && (file[i]!='/')) i--;
  if( i>0 ) {
    write("�ثe�ؿ��R" + file[0..i] + " �H __DIR__ ���N�C\n");
    room_code = replace_string(room_code, "\"" + file[0..i], "__DIR__\"");
  }

  if( file_size(file)!=-1 ) {
    write("�ɮ� " + file + " �w�s�b�M�n�R�����ɶܡS[y/n]");
    input_to("save_room_file", file, room_code);
    return 1;
  }

  return save_room_file("y", file, room_code);
}

int do_saveroom(string arg)
{
        object env;
        string str, *name, file, pre, suc;
        mapping prop;
        int i;
        string cwd;

        env = environment(this_player());
        file = file_name(env) + ".c";

        if (file_size(file) <= 0) return
          notify_fail ("�S���o�ж����ɮ�: "+file+"\n");

        name = explode (read_file (file), "\n");
        pre = "";
        for (i=0; i<sizeof (name); i++)
          if (strsrch (name[i], "void create") != 0)
            pre += name[i] + "\n";
          else break;
        pre += "void create ()\n{\n";

        i += 2;
        while (name && name[i][0..0] != "}") i++;
        suc = ""; i++;
        while (i<sizeof(name)) suc += name[i++]+"\n";

        prop = env->query_entire_dbase();

        str = pre;
        str = sprintf ("%s  set (\"short\", \"%s\");\n"
               "  set (\"long\", @LONG\n%sLONG);\n\n",
             str, prop["short"], prop["long"]);

        name = keys(prop);
        for(i=0; i<sizeof(name); i++) {
          if( member_array(name[i], special_props)!=-1 ) continue;
          if ( (intp(prop[name[i]]) && prop[name[i]]>0) ||
                (stringp(prop[name[i]]) && prop[name[i]] != "" ) ||
                (mapp(prop[name[i]]) && prop[name[i]] == ([])) ||
                sizeof (prop[name[i]]) > 0)
                    str += sprintf("  set(\"%s\", %O);\n",
                                   name[i], prop[name[i]] );
        }
        if (sizeof (suc) < 5)
         str += "\n  setup();\n  replace_program(ROOM);\n}\n";
        else
         str += "\n  setup();\n  replace_program(ROOM);\n}\n"+suc;


        // Replace current directory with __DIR__ macro to make relocatable code
        file = file_name(env);
        i = strlen(file)-1;
        while( (i > 0) && (file[i]!='/')) i--;
        if( i>0 ) {
          write("�ثe�ؿ��R" + file[0..i] + " �H __DIR__ ���N�C\n");
          str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
        }

        if( file_size(file)!=-1 ) {
                write("�ɮ� " + file + " �w�s�b�M�n�R�����ɶܡS[y/n]");
                input_to("save_room_file", file, str);
                return 1;
        }

        return save_room_file("y", file, str);
}

int init_var ()
{
  tmp["no_fight"]               =       0;
  tmp["no_magic"]               =       0;
  tmp["no_clean_up"]            =       0;
  tmp["valid_startroom"]        =       0;
  tmp["file_name"]              =       "";
  tmp["short"]                  =       "";
  tmp["long"]                   =       "";
  tmp["outdoors"]               =       "";
  tmp["item_desc"]              =       ([]);
  tmp["exits"]                  =       ([]);
  tmp["objects"]                =       ([]);
}


int query_autoload() { return 1; }