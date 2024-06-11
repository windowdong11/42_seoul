#ifndef RESULT_TPP
# define RESULT_TPP

/* include */
#include <stdexcept>

template <typename T>
class Result
{
public:
	enum ResultStatus
	{
		FAIL,
		SUCCESS,
	};
	Result(ResultStatus status, T value) : status(status), value(value) {}
	Result(const Result<T> &rhs) : status(rhs.status), value(rhs.value) {}
	Result<T> &operator=(const Result<T> &rhs)
	{
		status = rhs.status;
		value = rhs.value;
		return *this;
	}
	~Result() {}
	inline bool isSuccess() const { return status == SUCCESS; }
	inline T getValue() const
	{
		if (status == FAIL)
		{
			throw std::runtime_error(
					"Error : Trying to get value from failed exchange.\n"
					"How to fix : Check if exchange is successful by using isSuccess() before calling getValue().\n");
		}
		return value;
	}

private:
	ResultStatus status;
	T value;
	// private constructor to prevent default construction
	Result() {}
};
#endif