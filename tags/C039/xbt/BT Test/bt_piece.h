// bt_piece.h: interface for the Cbt_piece class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BT_PIECE_H__E6E03656_9830_4FFE_8F22_B3BF46E9D3C4__INCLUDED_)
#define AFX_BT_PIECE_H__E6E03656_9830_4FFE_8F22_B3BF46E9D3C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "bt_peer_link.h"
#include "stream_reader.h"

class Cbt_sub_piece
{
public:
	typedef map<Cbt_peer_link*, int> t_peers;

	t_peers m_peers;

	Cbt_sub_piece()
	{
		m_valid = false;
	}

	bool valid() const
	{
		return m_valid;
	}

	void valid(bool v)
	{
		if (v)
			m_peers.clear();
		m_valid = v;
	}
private:
	bool m_valid;
};

class Cbt_piece
{
public:
	typedef vector<Cbt_sub_piece> t_sub_pieces;
	
	int cb_sub_piece(int);
	int c_sub_pieces() const;
	bool check_peer(Cbt_peer_link*, int time_out);
	void erase_peer(Cbt_peer_link*);
	int next_invalid_sub_piece(Cbt_peer_link*);
	void load_state(Cstream_reader&);
	int pre_save_state() const;
	void save_state(Cstream_writer&) const;
	int pre_dump() const;
	void dump(Cstream_writer&) const;
	int rank() const;
	int resize(int v);
	void valid(bool v);
	int write(int offset, const char* s, int cb_s);
	Cbt_piece();

	int c_sub_pieces_left() const
	{
		return mc_sub_pieces_left;
	}

	int c_unrequested_sub_pieces() const
	{
		return mc_unrequested_sub_pieces;
	}

	int cb_sub_piece() const
	{
		return 32 << 10;
	}

	int priority() const
	{
		return m_priority;
	}

	void priority(int v)
	{
		m_priority = v;
	}

	const t_sub_pieces& sub_pieces() const
	{
		return m_sub_pieces;
	}

	int size() const
	{
		return m_size;
	}

	bool valid() const
	{
		return m_valid;
	}

	char m_hash[20];
	int mc_peers;
private:
	int mc_sub_pieces_left;
	int mc_unrequested_sub_pieces;
	char m_priority;
	int m_size;
	t_sub_pieces m_sub_pieces;
	bool m_valid;
};

#endif // !defined(AFX_BT_PIECE_H__E6E03656_9830_4FFE_8F22_B3BF46E9D3C4__INCLUDED_)