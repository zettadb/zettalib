-- $Id: q02-tpch02.sql 2657 2007-06-12 16:08:15Z rdempsey $
-- Second query in 100 GB stream0 (tpch02).
SELECT 
	S_ACCTBAL,
	S_NAME,
	N_NAME,
	P_PARTKEY,
	P_MFGR,
	S_ADDRESS,
	S_PHONE,
	S_COMMENT
FROM 
	PART,
	SUPPLIER,
	PARTSUPP,
	NATION,
	REGION
WHERE 
	P_PARTKEY = PS_PARTKEY AND
	S_SUPPKEY = PS_SUPPKEY AND
	P_SIZE = 40 AND
	P_TYPE LIKE '%%NICKEL' AND
	S_NATIONKEY = N_NATIONKEY AND
	N_REGIONKEY = R_REGIONKEY AND
	R_NAME = 'AFRICA' AND
	PS_SUPPLYCOST = ( 
		SELECT
			MIN(PS_SUPPLYCOST)
			FROM PARTSUPP,
			SUPPLIER,
			NATION,
			REGION
				WHERE 
				P_PARTKEY	= PS_PARTKEY AND
				S_SUPPKEY 	= PS_SUPPKEY AND
				S_NATIONKEY = N_NATIONKEY AND
				N_REGIONKEY = R_REGIONKEY AND
				R_NAME = 'AFRICA'
				)
ORDER BY 
	S_ACCTBAL DESC,
	N_NAME,
	S_NAME,
	P_PARTKEY;
