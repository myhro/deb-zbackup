// Copyright (c) 2012-2013 Konstantin Isakov <ikm@zbackup.org>
// Part of ZBackup. Licensed under GNU GPLv2 or later

#include "sha256.hh"

Sha256::Sha256()
{
  SHA256_Init( &ctx );
}

void Sha256::add( void const * data, size_t size )
{
  SHA256_Update( &ctx, data, size );
}

void Sha256::finish( void * result )
{
  SHA256_Final( ( unsigned char * ) result, &ctx );
}

string Sha256::finish()
{
  char buf[ Size ];
  finish( buf );

  return string( buf, buf + sizeof( buf ) );
}
