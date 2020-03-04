// unique.c

// This function returns 1 if this_object() is not the unique clone in
// the mud. Note that calling this function on master copy always return
// 0.
nomask int violate_unique()
{
                // update by tmr 2006/12/15
                // �qonly eq �אּ "day eq"
                // �C���ɼ�24�p�ɧY�i���o�@��
                        
        object *ob;
        int t, rnd;

        if( !clonep(this_object()) ) return 0;

        // Find all the cloned instance of this_object()
        ob = filter_array( children(base_name(this_object())), (: clonep :) );

        t = uptime();
                t /= 60;        
                t /= 60;
                t /= 24;

        if(t<1) t = 1;
        rnd = 80 - t*10;
        if( rnd<5 ) rnd = 5;
        // �W�[���v
         return sizeof(ob) > t || random(100) > rnd;
}

// This function returns the replica of this_object() if any.
object create_replica()
{
        string replica;
        object obj;

        seteuid(getuid());
        if( stringp(replica = this_object()->query("replica_ob")) )
                obj = new_ob(replica);
        else
                obj = 0;
        destruct(this_object());
        return obj;
}

int query_unique() { return 1; }

