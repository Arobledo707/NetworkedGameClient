// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerCommands.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ServerCommands.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* ServerCommand_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ServerCommand_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_ServerCommands_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_ServerCommands_2eproto() {
  protobuf_AddDesc_ServerCommands_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ServerCommands.proto");
  GOOGLE_CHECK(file != NULL);
  ServerCommand_descriptor_ = file->message_type(0);
  static const int ServerCommand_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerCommand, command_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerCommand, content_),
  };
  ServerCommand_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ServerCommand_descriptor_,
      ServerCommand::internal_default_instance(),
      ServerCommand_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerCommand, _has_bits_),
      -1,
      -1,
      sizeof(ServerCommand),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServerCommand, _internal_metadata_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ServerCommands_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ServerCommand_descriptor_, ServerCommand::internal_default_instance());
}

}  // namespace

void protobuf_ShutdownFile_ServerCommands_2eproto() {
  ServerCommand_default_instance_.Shutdown();
  delete ServerCommand_reflection_;
}

void protobuf_InitDefaults_ServerCommands_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::GetEmptyString();
  ServerCommand_default_instance_.DefaultConstruct();
  ServerCommand_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_ServerCommands_2eproto_once_);
void protobuf_InitDefaults_ServerCommands_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_ServerCommands_2eproto_once_,
                 &protobuf_InitDefaults_ServerCommands_2eproto_impl);
}
void protobuf_AddDesc_ServerCommands_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_ServerCommands_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024ServerCommands.proto\"1\n\rServerCommand\022"
    "\017\n\007command\030\001 \002(\005\022\017\n\007content\030\002 \003(\t", 73);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ServerCommands.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ServerCommands_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_ServerCommands_2eproto_once_);
void protobuf_AddDesc_ServerCommands_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_ServerCommands_2eproto_once_,
                 &protobuf_AddDesc_ServerCommands_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ServerCommands_2eproto {
  StaticDescriptorInitializer_ServerCommands_2eproto() {
    protobuf_AddDesc_ServerCommands_2eproto();
  }
} static_descriptor_initializer_ServerCommands_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ServerCommand::kCommandFieldNumber;
const int ServerCommand::kContentFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ServerCommand::ServerCommand()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_ServerCommands_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:ServerCommand)
}

void ServerCommand::InitAsDefaultInstance() {
}

ServerCommand::ServerCommand(const ServerCommand& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ServerCommand)
}

void ServerCommand::SharedCtor() {
  _cached_size_ = 0;
  command_ = 0;
}

ServerCommand::~ServerCommand() {
  // @@protoc_insertion_point(destructor:ServerCommand)
  SharedDtor();
}

void ServerCommand::SharedDtor() {
}

void ServerCommand::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ServerCommand::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerCommand_descriptor_;
}

const ServerCommand& ServerCommand::default_instance() {
  protobuf_InitDefaults_ServerCommands_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<ServerCommand> ServerCommand_default_instance_;

ServerCommand* ServerCommand::New(::google::protobuf::Arena* arena) const {
  ServerCommand* n = new ServerCommand;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ServerCommand::Clear() {
// @@protoc_insertion_point(message_clear_start:ServerCommand)
  command_ = 0;
  content_.Clear();
  _has_bits_.Clear();
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool ServerCommand::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ServerCommand)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 command = 1;
      case 1: {
        if (tag == 8) {
          set_has_command();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &command_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_content;
        break;
      }

      // repeated string content = 2;
      case 2: {
        if (tag == 18) {
         parse_content:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_content()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->content(this->content_size() - 1).data(),
            this->content(this->content_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "ServerCommand.content");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_content;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ServerCommand)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ServerCommand)
  return false;
#undef DO_
}

void ServerCommand::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ServerCommand)
  // required int32 command = 1;
  if (has_command()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->command(), output);
  }

  // repeated string content = 2;
  for (int i = 0; i < this->content_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->content(i).data(), this->content(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "ServerCommand.content");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->content(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ServerCommand)
}

::google::protobuf::uint8* ServerCommand::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:ServerCommand)
  // required int32 command = 1;
  if (has_command()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->command(), target);
  }

  // repeated string content = 2;
  for (int i = 0; i < this->content_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->content(i).data(), this->content(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "ServerCommand.content");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->content(i), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ServerCommand)
  return target;
}

size_t ServerCommand::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ServerCommand)
  size_t total_size = 0;

  // required int32 command = 1;
  if (has_command()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->command());
  }
  // repeated string content = 2;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->content_size());
  for (int i = 0; i < this->content_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->content(i));
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ServerCommand::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ServerCommand)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ServerCommand* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ServerCommand>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ServerCommand)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ServerCommand)
    UnsafeMergeFrom(*source);
  }
}

void ServerCommand::MergeFrom(const ServerCommand& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ServerCommand)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void ServerCommand::UnsafeMergeFrom(const ServerCommand& from) {
  GOOGLE_DCHECK(&from != this);
  content_.UnsafeMergeFrom(from.content_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_command()) {
      set_command(from.command());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::UnknownFieldSet::MergeToInternalMetdata(
      from.unknown_fields(), &_internal_metadata_);
  }
}

void ServerCommand::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ServerCommand)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ServerCommand::CopyFrom(const ServerCommand& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ServerCommand)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool ServerCommand::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ServerCommand::Swap(ServerCommand* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ServerCommand::InternalSwap(ServerCommand* other) {
  std::swap(command_, other->command_);
  content_.UnsafeArenaSwap(&other->content_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ServerCommand::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ServerCommand_descriptor_;
  metadata.reflection = ServerCommand_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ServerCommand

// required int32 command = 1;
bool ServerCommand::has_command() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void ServerCommand::set_has_command() {
  _has_bits_[0] |= 0x00000001u;
}
void ServerCommand::clear_has_command() {
  _has_bits_[0] &= ~0x00000001u;
}
void ServerCommand::clear_command() {
  command_ = 0;
  clear_has_command();
}
::google::protobuf::int32 ServerCommand::command() const {
  // @@protoc_insertion_point(field_get:ServerCommand.command)
  return command_;
}
void ServerCommand::set_command(::google::protobuf::int32 value) {
  set_has_command();
  command_ = value;
  // @@protoc_insertion_point(field_set:ServerCommand.command)
}

// repeated string content = 2;
int ServerCommand::content_size() const {
  return content_.size();
}
void ServerCommand::clear_content() {
  content_.Clear();
}
const ::std::string& ServerCommand::content(int index) const {
  // @@protoc_insertion_point(field_get:ServerCommand.content)
  return content_.Get(index);
}
::std::string* ServerCommand::mutable_content(int index) {
  // @@protoc_insertion_point(field_mutable:ServerCommand.content)
  return content_.Mutable(index);
}
void ServerCommand::set_content(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:ServerCommand.content)
  content_.Mutable(index)->assign(value);
}
void ServerCommand::set_content(int index, const char* value) {
  content_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:ServerCommand.content)
}
void ServerCommand::set_content(int index, const char* value, size_t size) {
  content_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ServerCommand.content)
}
::std::string* ServerCommand::add_content() {
  // @@protoc_insertion_point(field_add_mutable:ServerCommand.content)
  return content_.Add();
}
void ServerCommand::add_content(const ::std::string& value) {
  content_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:ServerCommand.content)
}
void ServerCommand::add_content(const char* value) {
  content_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:ServerCommand.content)
}
void ServerCommand::add_content(const char* value, size_t size) {
  content_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:ServerCommand.content)
}
const ::google::protobuf::RepeatedPtrField< ::std::string>&
ServerCommand::content() const {
  // @@protoc_insertion_point(field_list:ServerCommand.content)
  return content_;
}
::google::protobuf::RepeatedPtrField< ::std::string>*
ServerCommand::mutable_content() {
  // @@protoc_insertion_point(field_mutable_list:ServerCommand.content)
  return &content_;
}

inline const ServerCommand* ServerCommand::internal_default_instance() {
  return &ServerCommand_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
