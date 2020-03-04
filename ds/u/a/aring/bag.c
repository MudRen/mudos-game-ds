#include <ansi.h>;
inherit ITEM;

void resetname(int size);
int MAX_SIZE = 10;

void create()
{
        set_name(HIM"�Q��p�ֳU"NOR, ({ "small luck bag","bag" }) );
        set_weight(500);
        //set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("long", "�o�O�@�f�i�H�ˤJ�@�Ǫ��~���p�U�l�M�i�H�ΨӪ����O�s�@�Ǫ��~�C\n"
                        "inbag ���~id: �N�F���J�U��\n"
                        "outbag �s��: �N�F��q�U�����X\n"
                        "listbag: �ݳU�����F��\n"
                );
                set("value", 0);
                set("no_drop",1);
                set("no_sac",1);
                set("no_toss",1);
                set("maxsize",10);
                set("saveeq_type","suechi");
        }
}

int query_autoload() { return 1; }

void init()
{
        object me;
        
        me = this_player();
        if ( query("maxsize") )
                resetname(query("maxsize"));
        add_action("do_inbag","inbag");
        add_action("do_outbag","outbag");
        add_action("do_listbag","listbag");
        if ( wizardp(me) )
                add_action("do_setsize","setsize");
}

void resetname(int size)
{
        set_name(HIY" "+size+" "HIM"��p�ֳU"NOR, ({ "luck bag","bag" }) );
        MAX_SIZE = size;
}

int do_setsize(string arg)
{
        int newsize,tmpsize;
        
        if ( !arg ) return notify_fail("setsize �j�p\n");
        if ( sscanf(arg,"%d",newsize)!=1 )
                return notify_fail("�п�J�Ʀr.\n");
        //��n��U�l�ܤp�ɥ��ˬdnewsize+1��maxsize���O�_���s�F��
        if ( query("maxsize") > newsize )
        {
                tmpsize = newsize+1;
                while (tmpsize <= query("maxsize"))
                {
                        write(query("stored"+tmpsize)+"\n");
                        if ( query("stored"+tmpsize) )
                                return notify_fail("�A�n�Y�p�U�l�j�p�e, �n����j��s�j�p�����~���X��.\n");
                        tmpsize += 1;
                }
        }
        set("maxsize",newsize);
        resetname(newsize);
        write("�]�w�s���U�l�j�p�� "+newsize+".\n");
        return 1;
}

int do_inbag(string arg)
{
        object item,ppl;
        int cnt,i;
        mapping itemdb;
        
        ppl = this_player();
        if ( ppl->is_busy() )
                return notify_fail("�A�S�ũ�F��i�U�l��.\n");
        if ( ppl->is_fighting() )
                return notify_fail("�԰��������F��i�U�l��.\n");
        if ( !arg )
                return notify_fail("�A�n�񤰻�F���U�l��?\n");
        item = present(arg,ppl);
        if ( !item )
                return notify_fail("�o�̨S�� "+arg+" �o�ӪF��.\n");
        if ( item == this_object() )
                return notify_fail("�A�Q������?\n");
        if ( item->query_autoload() ||
                item->query("no_drop") ||
                item->query("no_toss") )
                return notify_fail("�o�˪F�褣���i�h.\n");
        if ( item->query("name") &&
                 strsrch(item->query("name"),"�q��")!=-1 &&
                 strsrch(item->query("name"),"���@")!=-1 )
                return notify_fail("�q�����@�L�ᤣ���i�h.\n");
        cnt = query("stored_cnt");
        if ( cnt >= MAX_SIZE ) return notify_fail("�̭��w�g��F "+MAX_SIZE+" �˪��~�F\n");
        cnt += 1;
        set("stored_cnt",cnt);
        i=1;
        while ( i <=MAX_SIZE )
        {
                if ( !query("stored_name"+i) )
                {
                        set("stored"+i,base_name(item));
                        set("stored_name"+i,item->short());
                        itemdb = item->query_entire_dbase();
                        map_delete(itemdb,"symbol");
                        map_delete(itemdb,"symbol2");
                        map_delete(itemdb,"symbol3");
                        map_delete(itemdb,"symbol_name");
                        set("itemdb"+i,itemdb);
                        break;
                }
                i = i+1;
        }
        message_vision(CYN"$N"NOR CYN"�N�@��"+item->name()+NOR CYN"��i"+this_object()->name()+NOR CYN"��.\n"NOR,ppl);
        destruct(item);
        return 1;
}

int do_outbag(string arg)
{
        object obj,ppl;
        int cnt,idx,i;
        string file,err,*dbkey;
        mapping itemdb;
        
        ppl = this_player();
        if ( ppl->is_busy() )
                return notify_fail("�A�S�űq�U�l�̮��F��.\n");
        if ( ppl->is_fighting() )
                return notify_fail("�԰�������q�U�l�̮��F��.\n");
        if ( !arg )
                return notify_fail("�A�n�q�U�l�̮����ӽs�����F��?\n");
        if ( sscanf(arg,"%d",idx)!=1 )
                return notify_fail("�п�J�Ʀr.\n");
        cnt = query("stored_cnt");
        if ( !query("stored"+idx) || idx < 1 ) return notify_fail("�S���o�ӽs�������~�b�U�l��.\n");
        file = query("stored"+idx);
        if ( !file )
                return notify_fail("�U�l�̨S���o�ӽs�����F��.\n");
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        if( file_size(file) < 0 )
                return notify_fail("�����ɮ�(" + file + ")���s�b, �гq���Ův�C\n");
        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("�����ɮ�(" + file + ")���J���ѡR" + err + ", \n�бN�T���^�����Ův�C\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("�����ɮ�(" + file + ")�ƻs���ѡR" + err + "\n�бN�T���^�����Ův�C\n");
                return 1;
        }
        if ( !obj->move(ppl) )
        {
                destruct(obj);
                return notify_fail("�A�����X�o�ӪF��, �]���ӭ��F\n");
        }
        if ( query("itemdb"+idx) )
        {
                itemdb = query("itemdb"+idx);
                dbkey = keys(itemdb);
                for ( i=0;i<sizeof(dbkey);i++ )
                        obj->set(dbkey[i],itemdb[dbkey[i]]);
        }
        message_vision(CYN"$N"NOR CYN"�N�@��"+obj->name()+NOR CYN"�q"+this_object()->name()+NOR CYN"���X��.\n"NOR,ppl);
        cnt -= 1;
        set("stored_cnt",cnt);
        delete("stored"+idx);
        delete("stored_name"+idx);
        delete("itemdb"+idx);
        return 1;
}

int do_listbag()
{
        int cnt,i;
        string msg;
        
        cnt = query("stored_cnt");
        
        if ( !cnt )
                return notify_fail("�o�ӳU�l�̨S������F��.\n");
        msg = "�U�l�̥ثe��۳o�ǪF��:\n";
        i = 1;
        while ( i <=MAX_SIZE )
        {
                if ( query("stored_name"+i) )
                        msg += "�s�� "+i+": "+query("stored_name"+i)+"\n";
                i = i+1;
        }
        tell_object(this_player(),msg);
        return 1;
}

